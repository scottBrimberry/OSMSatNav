#include "osmrelationmember.h"

OSMRelationMember::OSMRelationMember()
{
}

OSMRelationMember::OSMRelationMember( Type a, int b )
{
    m_type = a;
    m_ref = b;
}

OSMRelationMember::OSMRelationMember( QXmlStreamReader &xml )
{
    readMember( xml );
}

void OSMRelationMember::setType( Type type )
{
    m_type = type;
}

void OSMRelationMember::setRef( int ref )
{
    m_ref = ref;
}

OSMRelationMember::Type OSMRelationMember::type()
{
    return m_type;
}

int OSMRelationMember::ref()
{
    return m_ref;
}

OSMRelationMember OSMRelationMember::readMember( QXmlStreamReader &xml )
{
    if ( xml.attributes().value( "type" ).toString() == "node" )
        m_type = Node;
    else
        m_type = Way;

    m_ref = xml.attributes().value( "ref" ).toString().toInt();

    return *this;
}
