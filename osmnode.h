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
    
    @param related True if the node is related to a way or relation
    */
    void setRelated( bool related );
    /**
    Set whether the node forms a junction between two or more ways.
    
    @param junction True if the node forms a junction
    */
    void setJunction( bool junction );
    
    //Getters
    /**
    Get the unique id of the node
    
    @return The unique id of the node
    */
    int id();
    /**
    Get the x position of the node
    
    @return The x position of the node
    */
    double x();
    /**
    Get the y position of the node
    
    @return The y position of the node
    */
    double y();
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
    /**
    Get whether the node forms a junction between two or more ways
    
    @return True if the node forms a junction
    */
    bool junction();
    
  private:
    //Taken straight from XML
    int m_id;
    double m_lat;
    double m_lon;
    double m_x;
    double m_y;
    bool m_visible;
    //True if part of a relation (i.e. if false, then POI)
    bool m_related;
    //True if the node is part of more than one way
    bool m_junction;
};

#endif