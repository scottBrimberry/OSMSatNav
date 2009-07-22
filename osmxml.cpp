#include "osmxml.h"

#include "osmmap.h"

#include <QFile>
#include <QXmlStreamReader>

#include <QDebug>

bool OSMXml::readFile( QString filename, OSMMap* map )
{
  QXmlStreamReader xml;
  QFile file( filename );
  if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
  {
    return false;
  }
  
  xml.setDevice( &file );

  while ( !xml.atEnd() ) 
  {
    xml.readNext();
    
    if( xml.isStartElement() )
    {
      //#########################
      //# Start <bounds> tag    #
      //#########################
      if( xml.name() == "bounds" )
      {
        foreach( QXmlStreamAttribute i, xml.attributes() )
        {
          if( i.name() == "minlat" )
            map->setMinLat( i.value().toString().toDouble() );
          else if( i.name() == "maxlat" )
            map->setMaxLat( i.value().toString().toDouble() );
          else if( i.name() == "minlon" )
            map->setMinLon( i.value().toString().toDouble() );
          else if( i.name() == "maxlon" )
            map->setMaxLon( i.value().toString().toDouble() );
        }
      }
      
      //#########################
      //# Start <node> tag      #
      //#########################
      if( xml.name() == "node" )
      {
        OSMNode newNode;
        
        foreach( QXmlStreamAttribute i, xml.attributes() )
        {
          if( i.name() == "id" )
            newNode.setId( i.value().toString().toInt() );
          else if( i.name() == "lat" )
            newNode.setLat( i.value().toString().toDouble() );
          else if( i.name() == "lon" )
            newNode.setLon( i.value().toString().toDouble() );
          else if( i.name() == "visible" )
            newNode.setVisible( i.value() == "false" ? false : true ); //Comparison done on false so that it defaults to true
        }
        
        //Get tags
        while ( !( xml.isEndElement() && xml.name() == "node" ) )
        {
          xml.readNext();
          
          //Check for <tag> because other (XML) tags may be present
          if( xml.isStartElement() && xml.name() == "tag" )
          {
            if( xml.attributes().value( "k" ) != "" )
              newNode.addTag( xml );
          }
        }
        
        map->addNode( newNode );
      }
      //#########################
      //# End <node> tag        #
      //#########################
      
      
      //#########################
      //# Start <way> tag       #
      //#########################
      if( xml.name() == "way" )
      {
        OSMWay newWay;
        
        foreach( QXmlStreamAttribute i, xml.attributes() )
        {
          if( i.name() == "id" )
            newWay.setId( i.value().toString().toInt() );
          else if( i.name() == "visible" )
            newWay.setVisible( i.value() == "false" ? false : true ); //Comparison done on false so that it defaults to true
        }
        
        //Get tags
        while ( !( xml.isEndElement() && xml.name() == "way" ) )
        {
          xml.readNext();
          
          if( xml.isStartElement() )
          {
            if( xml.name() == "tag" )
            {
              if( xml.attributes().value( "k" ) != "" )
                newWay.addTag( xml );
            }
            else if( xml.name() == "nd" )
            {
              newWay.addNode( map->getNodePtrById( xml.attributes().value( "ref" ).toString().toInt() ) );
            }
          }
        }
        
        map->addWay( newWay );
        
      }
      //#########################
      //# End <way> tag         #
      //#########################
      
      //#########################
      //# Start <relation> tag  #
      //#########################
      if( xml.name() == "relation" )
      {
        OSMRelation newRelation( map );
        
        foreach( QXmlStreamAttribute i, xml.attributes() )
        {
          if( i.name() == "id" )
            newRelation.setId( i.value().toString().toInt() );
          else if( i.name() == "visible" )
            newRelation.setVisible( i.value() == "false" ? false : true ); //Comparison done on false so that it defaults to true
        }
        
        //Get tags
        while ( !( xml.isEndElement() && xml.name() == "relation" ) )
        {
          xml.readNext();
          
          if( xml.isStartElement() )
          {
            if( xml.name() == "tag" )
            {
              if( xml.attributes().value( "k" ) != "" )
                newRelation.addTag( xml );
            }
            else if( xml.name() == "member" )
            {
              newRelation.addMember( xml );
            }
          }
        }
        
        map->addRelation( newRelation );
        
      }
      //#########################
      //# End relation> tag     #
      //#########################
    }
  }
  
  return true;
}

bool OSMXml::writeFile( QString filename, OSMMap* map )
{
  //TODO: Implement me
  return false;
}
