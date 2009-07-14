#ifndef OSMRELATION_H
#define OSMRELATION_H

#include "osmtaggable.h"
#include "osmrelationmember.h"

class OSMMap;
class OSMNode;
class OSMWay;

/**
The OSMRelation class is used to hold information about relations within an OSMMap.
As the nodes and ways within a relation are stored only as id numbers, each 
instance of the OSMRelation class requires an OSMMap as its parent. This parent is
used to get pointers to the OSMNode and OSMWay objects for each member.
*/
class OSMRelation: public OSMTaggable
{
  public:
    /**
    Create an empty OSMRelation object
    
    @param parent The parent OSMMap object which the OSMRelation object is part of.
    */
    OSMRelation( OSMMap* parent ) ;
    /**
    Create an OSMRelation object with the specified unique id and visibility.
    
    @param parent The parent OSMMap object which the OSMRelation object is part of.
    @param id The numeric unique id of the relation
    @param visible True if the relation should be visible on the map
    */
    OSMRelation( OSMMap* parent, int id, bool visible );
    
    /**
    Add a member to the relation.
    
    @param member An OSMRelationMember object representing the member to be added.
    */
    void addMember( OSMRelationMember member );
       
    /**
    Read an OSMRelationMember object from the given QXmlStreamReader object and add
    it to the relation. The xml stream needs to be at the start of a member element. 
    (i.e. xml.isStartElement() && xml.name() == "member")
    
    @param xml The QXmlStreamReader to be read from
    */
    void addMember( QXmlStreamReader &xml );
    
    /**
    Return a QList containing all the members in the relation
    
    @return All the members in the relation
    */
    QList<OSMRelationMember> members();
    
    /**
    Returns the type of the provided member. This (or getMemberType( int ) ) should be used
    before getMemberNode() or getMemberWay() to ensure you use the correct function to get
    the OSMNode or OSMWay.
    
    @param member An OSMRelationMember object, the function will return the type of this
    object
    
    @return The type of the provided OSMRelationMember object
    */
    OSMRelationMember::Type getMemberType( OSMRelationMember member );
    
    /**
    Returns the type of the member at position i in the QList used to hold the members (the
    same QList returned my members() ). This (or getMemberType( OSMRelationMember ) ) should 
    be used before getMemberNode() or getMemberWay() to ensure you use the correct function 
    to get the OSMNode or OSMWay.
    
    @param i The position of the member within the QList
    
    @return The type of the member at position i (i.e. members().at( i ).type() )
    */
    OSMRelationMember::Type getMemberType( int i );
    
    /**
    This function uses OSMMap::getNodeById() in the parent OSMMap to return a pointer to the
    OSMNode object referenced by the OSMRelationMember provided. This function should be
    used in conjunction with getMemberType() to make sure the OSMRelationMember you are
    requesting represents a node, rather than a way.
    
    @param member The OSMRelationMember representing the OSMNode to be returned
    
    @return The OSMNode represented by member
    */
    OSMNode* getMemberNode( OSMRelationMember member );
    
    /**
    A convenience function, returns the OSMNode represented by members().at( i )
    
    @see getMemberNode( OSMRelationMember )
    
    @param i The index of the member
    
    @return The OSMNode represented my members().at( i )
    */
    OSMNode* getMemberNode( int i );
    
    /**
    This function uses OSMMap::getWayById() in the parent OSMMap to return a pointer to the
    OSMWay object referenced by the OSMRelationMember provided. This function should be
    used in conjunction with getMemberType() to make sure the OSMRelationMember you are
    requesting represents a way, rather than a node.
    
    @param member The OSMRelationMember representing the OSMWay to be returned
    
    @return The OSMWay represented by member
    */
    OSMWay* getMemberWay( OSMRelationMember member );
    
    /**
    A convenience function, returns the OSMWay represented by members().at( i )
    
    @see getMemberWay( OSMRelationMember )
    
    @param i The index of the member
    
    @return The OSMWay represented my members().at( i )
    */
    OSMWay* getMemberWay( int i );
    
    /**
    Set the id of the relation
    
    @param id The id of the realtion
    */
    void setId( int id );
    
    /**
    Set the visibility of the relations members
    
    @param visible True if the relation is to be shown on the map
    */
    void setVisible( bool visible );
    
    /**
    Set whether the relation is part of another relation
    
    @param True if the relation is related
    */
    void setRelated( bool related );
    
    /**
    Returns the id of the relation
    
    @return The id of the relation
    */
    int id();
    
    /**
    Returns true if the relation is to be shown on the map
    
    @return The visibility of the relation
    */
    bool visible();
    
    /**
    Returns true if the relation is part of another relation
    
    @return True if the realtion is related
    */
    bool related();
    
  private:
    //Parent OSMMap
    OSMMap* m_parent;
    //Taken straight from XML
    int m_id;
    bool m_visible;
    //True if part of a relation (i.e. if false, then road)
    //TODO: Check if no relation does = road (maybe relations can be roads too?)
    bool m_related;
    //The nodes that make up the way
    QList<OSMRelationMember> m_members;
    
};

#endif