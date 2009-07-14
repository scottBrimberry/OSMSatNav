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
    void addMember( QXmlStreamReader &xml );
    
    QList<OSMRelationMember> members();
    
    //Due to OSMNode and OSMWay being completely and utterly incompatible,
    //i.e. there is no way of creating a useful superclass, I will have to
    //implement two functions to retreive members, one fro each class.
    //The calling code will have to determine the type before calling the
    //correct function (using getType()).
    
    //Get member type
    OSMRelationMember::Type getMemberType( OSMRelationMember member );
    OSMRelationMember::Type getMemberType( int i );
    
    //Get OSMNode from OSMRelationMember object
    OSMNode* getMemberNode( OSMRelationMember member );
    
    //Get OSMNode by index in the QList
    OSMNode* getMemberNode( int i );
    
    //Get OSMWay from OSMRelationMember object
    OSMWay* getMemberWay( OSMRelationMember member );
    
    //Get OSMWay by index in the QList
    OSMWay* getMemberWay( int i );
    
    void setId( int id );
    void setVisible( bool visible );
    void setRelated( bool related );
    
    int id();
    bool visible();
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