#include "osmnode.h"

#include "mercator.h"

OSMNode::OSMNode() 
{
}

OSMNode::OSMNode( int id, double lat, double lon, bool visible )
{
  m_id = id;
  setLat( lat );
  setLon( lon );
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
  m_y = Mercator::LatToY( lat );
}

//TODO: Ensure the centre of map is needed
void OSMNode::setLon( double lon ) 
{
  m_lon = lon; 
  m_x = Mercator::LonToX( lon );
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

double OSMNode::x() 
{
  return m_x; 
}

double OSMNode::y() 
{
  return m_y;
}

bool OSMNode::visible() 
{
  return m_visible; 
}

bool OSMNode::related() 
{
  return m_related;
}
