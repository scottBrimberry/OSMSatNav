#ifndef OSMRELATIONMEMBER_H
#define OSMRELATIONMEMBER_H

#include <QXmlStreamReader>

/**
The OSMRelationMember class is used to store information about individual members
within an OSMRelation object. The OSMRelationMember class is largely useless
unless it is being used in conjunction with an OSMRelation and, in turn an OSMMap
as only the id of a node or way is stored within the OSMRelationMember, and the
OSMRelation and OSMMap are needed to get a pointer to the OSMNode or OSMWay object.
*/
class OSMRelationMember
{
public:
    /**
    Used to specify the type of a relation member
    */
    enum Type
    {
        Node,
        Way
    };

    /**
    Create an empty OSMRelationMember object
    */
    OSMRelationMember();
    /**
    Create an OSMRelationMember object with the given type and reference

    @param a The type of the member
    @param b The id number of the member
    */
    OSMRelationMember( Type a, int b );
    /**
    Read an OSMRelationMember object from the given QXmlStreamReader object. The
    xml stream needs to be at the start of a member element. (i.e.
    xml.isStartElement() && xml.name() == "member")

    @param xml The QXmlStreamReader to be read from
    */
    OSMRelationMember( QXmlStreamReader &xml );

    /**
    Sets the type of the member

    @param type The type of the member
    */
    void setType( Type type );

    /**
    Sets the id of the member

    @param ref The reference id number
    */
    void setRef( int ref );

    /**
    Returns the type of the member

    @return The type of the member
    */
    Type type();

    /**
    Returns the id of the member

    @return The reference id number of the member
    */
    int ref();

    /**
    Read the type and id number of the member from the specified XML stream. The
    xml stream needs to be at the start of a member element. (i.e.
    xml.isStartElement() && xml.name() == "member")
    A copy of the member is returned so that it can be used in other functions.

    @param xml The XML stream to read from

    @return A copy of the OSMRelationMember after the XML data has been read.
    */
    OSMRelationMember readMember( QXmlStreamReader &xml );

private:
    Type m_type;
    int m_ref;
};

#endif
