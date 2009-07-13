#include "osmnode.h"

OSMNode::OSMNode() 
{
}

OSMNode::OSMNode( int id, double lat, double lon, bool visible )
{
  m_id = id;
  m_lat = lat;
  m_lon = lon;
  m_visible = visible;
  m_related = false;
}

void OSMNode::setId( int id ) 
{
  m_id = id; 
}

void OSMNode::setLat( double lat ) 
{
  m_lat = lat; 
}

void OSMNode::setLon( double lon ) 
{
  m_lon = lon; 
}

void OSMNode::setVisible( bool visible ) 
{
  m_visible = visible; 
}

void OSMNode::setRelated( bool related ) 
{
  m_related = related; 
}

int OSMNode::id() 
{
  return m_id; 
}

double OSMNode::lat() 
{
  return m_lat; 
}

double OSMNode::lon() 
{
  return m_lon;
}

bool OSMNode::visible() 
{
  return m_visible; 
}

bool OSMNode::related() 
{
  return m_related;
}
