#include "osmway.h"

#include "osmnode.h"

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
