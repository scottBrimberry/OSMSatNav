#include <QDebug>

#include <QApplication>
#include <QtSql>


int main( int argc, char** argv )
{  
  QApplication app( argc, argv );
  
  //Set up database connection
  QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
  db.setHostName("localhost");
  db.setDatabaseName("osmsatnav");
  db.setUserName("root");
  db.setPassword("br88root");
  
  if( !db.open() )
  {
    if( db.lastError().number() == 1049 ) //Database does not exist
    {
      //Create database
      db.setDatabaseName("");
      
      if( !db.open() )
        qDebug() << " Error opening connection for adding database: " << db.lastError();
      
      QSqlQuery query;
      query.exec("CREATE DATABASE osmsatnav");
      
      db.close();
      
      db.setDatabaseName("osmsatnav");
      
      if( !db.open() )
      {
        qDebug() << "Error opening connection after adding database: " << db.lastError();
        return 0;
      }
  
      //Create tables
      QSqlQuery query;
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
  }
  
  
  
  //app.exec();
  
}