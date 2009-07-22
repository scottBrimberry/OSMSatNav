#include "osmrelation.h"

#include "osmmap.h"
#include "osmnode.h"
#include "osmway.h"
#include <QDebug>

OSMRelation::OSMRelation( OSMMap* parent ) 
{
  m_parent = parent;
}

OSMRelation::OSMRelation( OSMMap* parent, int id, bool visible )
{
  m_parent = parent;
  m_id = id;
  m_visible = visible;
  m_related = false;
}

void OSMRelation::addMember( OSMRelationMember member )
{ 
  m_members.append( member );
  //TODO: Work out best way of marking nodes as part of relation (rather than way)

}

void OSMRelation::addMember( QXmlStreamReader &xml )
{
  OSMRelationMember::Type type;
  if( xml.attributes().value( "type" ) == "way" )
    type = OSMRelationMember::Way;
  else
    type = OSMRelationMember::Node;
  
  addMember( OSMRelationMember( type, xml.attributes().value( "ref" ).toString().toInt() ) );
}

QList<OSMRelationMember> OSMRelation::members() 
{ 
  return m_members; 
}

OSMRelationMember::Type OSMRelation::getMemberType( OSMRelationMember member ) 
{ 
  return member.type(); 
}

OSMRelationMember::Type OSMRelation::getMemberType( int i ) 
{
  return getMemberType( m_members.at( i ) ); 
}

OSMNode* OSMRelation::getMemberNode( OSMRelationMember member )
{
  if( member.type() == OSMRelationMember::Node )
    return m_parent->getNodePtrById( member.ref() );
  else
    return 0;
}

OSMNode* OSMRelation::getMemberNode( int i ) 
{
  return getMemberNode( m_members.at( i ) );
}

OSMWay* OSMRelation::getMemberWay( OSMRelationMember member )
{
  if( member.type() == OSMRelationMember::Way )
    return m_parent->getWayPtrById( member.ref() );
  else
    return 0;
}

OSMWay* OSMRelation::getMemberWay( int i ) 
{
  return getMemberWay( m_members.at( i ) ); 
}

void OSMRelation::setId( int id ) 
{ 
  m_id = id; 
}

void OSMRelation::setVisible( bool visible ) 
{
  m_visible = visible; 
}

void OSMRelation::setRelated( bool related )
{
  m_related = related; 
}

int OSMRelation::id() 
{
  return m_id; 
}

bool OSMRelation::visible() 
{
  return m_visible; 
}
  
bool OSMRelation::related() 
{
  return m_related; 
}
