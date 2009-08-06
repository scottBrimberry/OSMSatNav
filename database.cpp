#include "database.h"

#include "osmmap.h"

#include <QtSql>

bool OSMDatabase::open( QString host, QString name, QString user, QString pass )
{  
  QSqlDatabase db = QSqlDatabase::addDatabase( "QMYSQL" );
  db.setHostName( host );
  db.setDatabaseName( name );
  db.setUserName( user );
  db.setPassword( pass );
  
  if( !db.open() )
  {
    if( db.lastError().number() == 1049 ) //Database does not exist
    {
      //Create database
      db.setDatabaseName("");
      
      if( !db.open() )
        qDebug() << " Error opening connection for adding database: " << db.lastError();
      
      QSqlQuery query;
      query.exec( "CREATE DATABASE osmsatnav" );
      
      db.close();
      
      db.setDatabaseName( "osmsatnav" );
      
      if( !db.open() )
      {
        qDebug() << "Error opening connection after adding database: " << db.lastError();
        return false;
      }
  
      //Create tables
      query.exec( "CREATE TABLE Nodes( Id int, Longitude float, Latitude float )" );
      query.exec( "CREATE TABLE Ways( Id int )" );
      query.exec( "CREATE TABLE Relations( Id int )" );
      query.exec( "CREATE TABLE Tags ( Id int, Key varchar(255), Value varchar(255) )" );
      query.exec( "CREATE TABLE NodeTags ( Node int, Tag int )" );
      query.exec( "CREATE TABLE WayNodes ( Way int, Node int )" );
      query.exec( "CREATE TABLE WayTags ( Way int, Tag int )" );
      query.exec( "CREATE TABLE RelationWays ( Relation int, Way int )" );
      query.exec( "CREATE TABLE RelationNodes ( Relation int, Node int )" );
      query.exec( "CREATE TABLE RelationTags ( Relation int, Tag int )" );
    }
    
    return false;
  }
  
  return true;
}

bool OSMDatabase::isOpen()
{
  return QSqlDatabase::database().isOpen();
}

void OSMDatabase::writeMap( OSMMap* map )
{
  //Check for open database
  if( !isOpen() )
    return;
  
  QSqlQuery query;
  
  //Write each node to the database
  foreach( OSMNode i, map->nodes() )
  {
    //Check for existing node - only update lat and lon if it exists
    query = QSqlQuery( QString().sprintf( "SELECT * FROM Nodes WHERE Id = %i", i.id() ) );
    
    if( query.size() > 0 )
      query.exec( QString().sprintf( "UPDATE Nodes SET Longitude = %f, Latitude = %f WHERE Id = %i", i.lon(), i.lat(), i.id() ) );
    else
      query.exec( QString().sprintf( "INSERT INTO Nodes VALUES ( %i, %f, %f )", i.id(), i.lon(), i.lat() ) );
  }
  
  //Write each way and populate the WayNodes table
  foreach( OSMWay i, map->ways() )
  {
    query = QSqlQuery( QString().sprintf( "SELECT * FROM Ways WHERE Id = %i", i.id() ) );
    
    if( query.size() > 0 )
    {
      //Remove existing nodes (will be re-added later)
      query.exec( QString().sprintf( "DELETE FROM WayNodes WHERE Way = %i", i.id() ) );
    }
    else
    {
      query.exec( QString().sprintf( "INSERT INTO Ways VALUES ( %i )", i.id() ) );
    }
    
    foreach( OSMNode* j, i.nodes() )
    {
      query.exec( QString().sprintf( "INSERT INTO WayNodes VALUES ( %i, %i )", i.id(), j->id() ) );
    }
  }
  
  //Write each relation and populate the RelationNode and RelationWay tables
  foreach( OSMRelation i, map->relations() )
  {
    query = QSqlQuery( QString().sprintf( "SELECT * FROM Relations WHERE Id = %i )", i.id() ) );
    
    if( query.size() > 0 )
    {
      //Delete ways and nodes, will be repopulated later
      query.exec( QString().sprintf( "DELETE FROM RelationNodes WHERE Relation = %i )", i.id() ) );
      query.exec( QString().sprintf( "DELETE FROM RelationWays WHERE Relation = %i )", i.id() ) );
    }
    else
    {
      query.exec( QString().sprintf( "INSERT INTO Relations VALUES ( %i )", i.id() ) );
    }
    
    //Populate RelationWays and RelationNodes
    foreach( OSMRelationMember j, i.members() )
    {
      if( j.type() == OSMRelationMember::Way )
	query.exec( QString().sprintf( "INSERT INTO RelationWays VALUES ( %i, %i )", i.id(), j.ref() ) );
      else
	query.exec( QString().sprintf(" INSERT INTO RelationNodes VALUES ( %i, %i )", i.id(), j.ref() ) );
    }
  }
}
