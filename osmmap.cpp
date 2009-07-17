#include "osmmap.h"

#include "mercator.h"
#include "osmrelation.h"

#include <QDebug>

OSMMap::OSMMap() 
{
  m_zoomlevel = 0;
}

void OSMMap::setMinLat( double lat ) { m_minlat = lat; m_miny = Mercator::LatToY( lat ); }
void OSMMap::setMaxLat( double lat ) { m_maxlat = lat; m_maxy = Mercator::LatToY( lat ); }
void OSMMap::setMinLon( double lon ) { m_minlon = lon; m_minx = Mercator::LonToX( lon ); }
void OSMMap::setMaxLon( double lon ) { m_maxlon = lon; m_maxx = Mercator::LonToX( lon ); }

double OSMMap::minLat() { return m_minlat; }
double OSMMap::maxLat() { return m_maxlat; }
double OSMMap::minLon() { return m_minlon; }
double OSMMap::maxLon() { return m_maxlon; }

double OSMMap::minX() { return m_minx; }
double OSMMap::maxX() { return m_maxx; }
double OSMMap::minY() { return m_miny; }
double OSMMap::maxY() { return m_maxy; }

void OSMMap::addNode( OSMNode node ) 
{ 
  m_nodes.append( node ); 
}

QList<OSMNode> OSMMap::nodes() 
{
  return m_nodes; 
}

OSMNode OSMMap::node( int id ) 
{
  return m_nodes.at( id ); 
}

OSMNode* OSMMap::getNodePtrById( int id )
{
  for( int i = 0; i < m_nodes.count(); i++ )
  {
    if( m_nodes[i].id() == id )
      return &m_nodes[i];
  }
  
  return 0;
}

void OSMMap::addWay( OSMWay way ) 
{
  m_ways.append( way ); 
}

QList<OSMWay> OSMMap::ways() 
{
  return m_ways; 
}

OSMWay OSMMap::way( int id ) 
{
  return m_ways.at( id ); 
}

OSMWay* OSMMap::getWayPtrById( int id )
{
  for( int i = 0; i < m_ways.count(); i++ )
  {
    if( m_ways[i].id() == id )
      return &m_ways[i];
  }
  
  return 0;
}

void OSMMap::addRelation( OSMRelation relation ) 
{
  m_relations.append( relation ); 
}

QList<OSMRelation> OSMMap::relations() 
{
  return m_relations; 
}

OSMRelation OSMMap::relation( int id ) 
{
  return m_relations.at( id ); 
}

OSMRelation* OSMMap::getRelationPtrById( int id )
{
  for( int i = 0; i < m_relations.count(); i++ )
  {
    if( m_relations[i].id() == id )
      return &m_relations[i];
  }
  
  return 0;
}

void OSMMap::paint( QPainter* painter )
{
  //Ways
  foreach( OSMWay i, ways() )
  {
    //TODO: The min lat and lon need to be part of the object read from the XML file
    i.paint( painter, m_minx, m_miny, zoomMultiplier() );
  }
}

void OSMMap::zoomIn( int steps )
{
  m_zoomlevel += steps;
}

void OSMMap::zoomOut( int steps )
{
  m_zoomlevel -= steps;
}

void OSMMap::zoom( int level )
{
  m_zoomlevel = level;
}

int OSMMap::zoomMultiplier()
{
  //Zoom level 0 displays entire map in 800x800 display
  
  //Get zoom multiplier at level 0
  int multiplier;
  
  if( ( m_maxx - m_minx ) > ( m_maxy - m_miny ) )
    multiplier = 800 / ( m_maxx - m_minx );
  else
    multiplier = 800 / ( m_maxy - m_miny );
  
  for( int i = 0; i < m_zoomlevel; i++ )
    multiplier = multiplier * 2;
  
  return multiplier;
}
