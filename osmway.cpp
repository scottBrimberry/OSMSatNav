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

void OSMWay::paint( QPainter* painter, double minx, double miny )
{
  QPolygon polygon;
  foreach( OSMNode* i, nodes() )
  {
    //TODO: The *2000 (or whatever it is now) is for zoom purposes, it needs to be part of some sort of
    //zoom feature/variable
    polygon.append( QPoint( (i->x() - minx) * 2000, painter->device()->height() - (i->y() - miny) * 2000 ) );
  }
  
  QString value;
  
  if( hasTag( "waterway", value ) )
    painter->setPen( QPen( QBrush( Qt::blue ), 2 ) );
  else if( hasTag( "highway", value ) && ( value == "footway" || value == "cycleway" ) ) //Footpath
    painter->setPen( QPen(QBrush( Qt::red ), 1, Qt::DotLine ) );
  else if( hasTag( "highway", value ) && ( value.startsWith( "motorway" ) ) ) //Motorway
    painter->setPen( QPen(QBrush( Qt::blue ), 2 ) );
  else if( hasTag( "highway", value ) && ( value.startsWith( "trunk" ) ) ) //Highway (A Road)
    painter->setPen( QPen(QBrush( Qt::green ), 2 ) );
  else if( hasTag( "highway", value ) && ( value.startsWith( "primary" ) ) ) //Highway (A Road)
    painter->setPen( QPen(QBrush( Qt::red ), 2 ) );
  else if( hasTag( "highway", value ) && ( value.startsWith( "secondary" ) ) ) //Highway (A Road)
    painter->setPen( QPen(QBrush( QColor( 255, 127, 0 ) ), 2 ) );
  else if( hasTag( "highway", value ) && ( value.startsWith( "tertiary" ) ) ) //Highway (A Road)
    painter->setPen( QPen(QBrush( Qt::yellow ), 2 ) );
  else if( hasTag( "highway", value ) ) //Other road (unclassified, redidential)
    painter->setPen( QPen(QBrush( Qt::white ), 2 ) );
  else if( hasTag( "railway", value ) )
    painter->setPen( QPen(QBrush( Qt::black ), 2 ) );
  else
    painter->setPen( QPen( QBrush( Qt::transparent ), 0 ) );
  
  painter->drawPolyline( polygon );
}
