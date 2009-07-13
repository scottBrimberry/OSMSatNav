#ifndef OSMMAP_H
#define OSMMAP_H

#include <QList>

#include "osmnode.h"
#include "osmway.h"
#include "osmrelation.h"

class OSMRelation;

/**
 The OSMMap class holds all nodes, ways and relations representing an area.
*/
class OSMMap
{
  public:
    /** Create an empty Map */
    OSMMap();
    
    /**
    Add an OSMNode object to the map 
    
    @param node An OSMNode object representing the node the be added.
    */
    void addNode( OSMNode node );
    
    /**
    Return all nodes in the map as a QList. Be aware that for large maps, this list
    can be very large, so take care when using. Use getNodePtrById( int ) or node( int )
    if you need just one node.
      
    @see getNodePtrById( int )
    @see node( int )
    
    @return A QList<OSMNode> containing all the nodes in the map
    */
    QList<OSMNode> nodes();
    
    /**
    Return the node at position id in the list of nodes. Equivalent to nodes().at( id ).
    
    @see nodes()
    @see getNodePtrById( int )
    
    @param id The position of the node within the QList
    
    @return An OSMNode object representing the node at position id.
    */
    OSMNode node( int id );
    
    /**
    Returns pointer to the node with the ID specified. Unlike node(), this function matches
    the specified id to OSMNode#m_id rather than the position in the list.
    This function is used primarily to add a node to a way or relation, be aware that, as 
    it is a pointer, any changes made to the returned object will be relflected in the OSMMap 
    object.
    
    @see nodes()
    @see node( int )
    
    @param id The id of the node to return
    
    @return A pointer to the requested OSMNode
    */
    OSMNode* getNodePtrById( int id );
    
    /**
    Add an OSMWay object to the map 
    
    @param way An OSMWay object representing the node the be added.
    */
    void addWay( OSMWay way );
    
    /**
    Return all ways in the map as a QList. Be aware that for large maps, this list
    can be very large, so take care when using. Use getWayPtrById( int ) or way( int )
    if you need just one node.
      
    @see getWayPtrById( int )
    @see way( int )
    
    @return A QList<OSMWay> containing all the ways in the map
    */
    QList<OSMWay> ways();
    
    /**
    Return the way at position id in the list of ways. Equivalent to ways().at( id ).
    
    @see ways()
    @see getWayPtrById( int )
    
    @param id The position of the way within the QList
    
    @return An OSMWay object representing the way at position id.
    */
    OSMWay way( int id );
    
    /**
    Returns pointer to the way with the ID specified. Unlike way(), this function matches
    the specified id to OSMWay#m_id rather than the position in the list.
    This function is used primarily to add a way to a relation, be aware that, as 
    it is a pointer, any changes made to the returned object will be relflected in the OSMMap 
    object.
    
    @see ways()
    @see way( int )
    
    @param id The id of the way to return
    
    @return A pointer to the requested OSMWay
    */
    OSMWay* getWayPtrById( int id );
    
    /**
    Add an OSMRelation object to the map 
    
    @param relation An OSMRelation object representing the node the be added.
    */
    void addRelation( OSMRelation relation );
    
    /**
    Return all relations in the map as a QList. Be aware that for large maps, this list
    can be very large, so take care when using. Use getRelationPtrById( int ) or relation( int )
    if you need just one node.
      
    @see getRelationPtrById( int )
    @see relation( int )
    
    @return A QList<OSMNode> containing all the relations in the map
    */
    QList<OSMRelation> relations();
    
    /**
    Return the relation at position id in the list of relations. Equivalent to relations().at( id ).
    
    @see relations()
    @see getRelationPtrById( int )
    
    @param id The position of the relation within the QList
    
    @return An OSMRelation object representing the relation at position id.
    */
    OSMRelation relation( int id );
    
    /**
    Returns pointer to the relation with the ID specified. Unlike relation(), this function matches
    the specified id to OSMRelation#m_id rather than the position in the list.
    This function is used primarily to add a relation to another relation, be aware that, as 
    it is a pointer, any changes made to the returned object will be relflected in the OSMMap 
    object.
    
    @see relations()
    @see relation( int )
    
    @param id The id of the relation to return
    
    @return A pointer to the requested OSMRelation
    */
    OSMRelation* getRelationPtrById( int id );
    
  private:
    QList<OSMNode> m_nodes;
    QList<OSMWay> m_ways;
    QList<OSMRelation> m_relations;
};

#endif