#include <QApplication>
#include <QDebug>
#include <QFile>
#include <QLabel>
#include <QPainter>
#include <QXmlStreamReader>

#include "osmmap.h"
#include "osmxml.h"

#include "mercator.h"

int main( int argc, char** argv )
{  
  OSMMap map;
  
  OSMXml::readFile( "/home/gary/Documents/shrewsbury-whole.osm", &map );
 
  //BEGIN TEST

  int count = 0;
  
  foreach( OSMNode i, map.nodes() )
  {
    if( i.junction() )
      count++;
  }
  
  qDebug() << "Nodes: " << count;
  
  qDebug() << "All Nodes: " << map.nodes().count();
  
  qDebug() << "Ways: " << map.ways().count();
  qDebug() << "Relations: " << map.relations().count();
  
  count = 0;
  
  foreach( OSMRelation i, map.relations() ) 
  {
    count += i.members().count();
  }
  
  qDebug() << "Members: " << count;
  
  return 0;
  
  //END TEST
  
}