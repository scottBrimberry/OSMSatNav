#include "osmway.h"

#include "osmnode.h"

#include <QDebug>

OSMWay::OSMWay() 
{
}

OSMWay::OSMWay( int id, bool visible )
{
  m_id = id;
  m_visible = visible;
  m_related = false;
}

void OSMWay::addNode( OSMNode* node ) 
{
  node->setRelated( true );
  m_nodes.append( node ); 
}

QList<OSMNode*> OSMWay::nodes() 
{
  return m_nodes; 
}

void OSMWay::setId( int id ) 
{
  m_id = id; 
}

void OSMWay::setVisible( bool visible ) 
{
  m_visible = visible;
}

void OSMWay::setRelated( bool related ) 
{
  m_related = related; 
}

int OSMWay::id() 
{
  return m_id; 
}

bool OSMWay::visible() 
{
  return m_visible; 
}

bool OSMWay::related() 
{
  return m_related; 
}

void OSMWay::paint( QPainter* painter, double minx, double miny, int zoomMultiplier )
{  
  QPolygon polygon;
  foreach( OSMNode* i, nodes() )
  {
    //TODO: The *2000 (or whatever it is now) is for zoom purposes, it needs to be part of some sort of
    //zoom feature/variable
    polygon.append( QPoint( (i->x() - minx) * zoomMultiplier, painter->device()->height() - (i->y() - miny) * zoomMultiplier ) );
  }
  
  QString value;
  
  painter->setPen( QPen( QBrush( QColor( 0, 0, 0, 50 ) ), 1 ) );
  
  painter->drawPolyline( polygon );
}
