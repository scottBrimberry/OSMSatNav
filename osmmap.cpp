#include "osmmap.h"

#include "mercator.h"
#include "osmrelation.h"

OSMMap::OSMMap() {}

//TODO: Check cnter is needed
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
    //TODO: The mim lat and lon need to be part of the object read from the XML file
    i.paint( painter, 52.622, -2.5293 );
  }
}