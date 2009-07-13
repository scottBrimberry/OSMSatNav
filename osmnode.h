#ifndef OSMNODE_H
#define OSMNODE_H

#include "osmtaggable.h"

/**
The OSMNode class is used to handle data relating to nodes on a map. This class
is used for nodes such as POI's and Town/City markers, but is also used as part
of the OSMWay and OSMRelation classes to hold the nodes that make up different
ways and relations.
*/
class OSMNode: public OSMTaggable
{
  public:
    /**
    Create an empty OSMNode object
    */
    OSMNode();
    /**
    Create an OSMNode object and initialise the members with the given values
    
    @param id The numerical unique id of the node
    @param lat The latitude of the node in degrees
    @param lon The longitude of the node in degrees
    @param visible True if the node should be visible on the map
    */
    OSMNode( int id, double lat, double lon, bool visible );
    
    //Setters
    /**
    Set the numerical unique id of the node
    
    @param id The numerical unique id of the node
    */
    void setId( int id );
    /**
    Set the latitude of the node
    
    @param lat The latitude of the node
    */
    void setLat( double lat );
    /**
    Set the longitude of the node
    
    @param lon The longitude of the node
    */
    void setLon( double lon );
    /**
    Set whether the node is visible on the map
    
    @param visible True if the node should be visible on the map
    */
    void setVisible( bool visible );
    /**
    Set whether the node is part of a way or relation. If it is related to
    a way or relation, it will be rendered on the map as part of that way
    or relation instead of independently as a POI
    
    @param related True is the node is related to a way or relation
    */
    void setRelated( bool related );
    
    //Getters
    /**
    Get the unique id of the node
    
    @return The unique id of the node
    */
    int id();
    /**
    Get the latitude of the node
    
    @return The latitude of the node
    */
    double lat();
    /**
    Get the longitude of the node
    
    @return The longitude of the node
    */
    double lon();
    /**
    Get whether the node is shown on the map
    
    @return True if the node is visible
    */
    bool visible();
    /**
    Get whether the node is related to a way or relation
    
    @return True if the node is related to a way or relation
    */
    bool related();
    
  private:
    //Taken straight from XML
    int m_id;
    double m_lat;
    double m_lon;
    bool m_visible;
    //True if part of a relation (i.e. if false, then POI)
    bool m_related;
};

#endif