#include "osmmap.h"

#include "osmrelation.h"

OSMMap::OSMMap()
{
}

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