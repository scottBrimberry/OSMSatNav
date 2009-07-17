#ifndef OSMWAY_H
#define OSMWAY_H

#include <QPainter>

#include "osmtaggable.h"

class OSMNode;

class OSMWay: public OSMTaggable
{
  public:
    /**
    Create an empty OSMWay object
    */
    OSMWay();
    
    /**
    Create an OSMWay object and initialise the id and visibility members with
    the given values
    
    @param id The id of the way
    @param visible True if the way is to be displayed on the map
    */
    OSMWay( int id, bool visible );
    
    /**
    Add a node to the way. The OSMNode provided is added to the way as a pointer
    and should usually be part of the same OSMMap as the OSMWay object that it is
    being added to.
    
    @param node The OWMNode to add to the way
    */
    void addNode( OSMNode* node );
    /**
    Return a QList containing all the nodes within the OSMWay object.
    
    @return All the OSMNodes in the OSMWay
    */
    QList<OSMNode*> nodes();
    
    /**
    Set the numerical unique id of the way
    
    @param id The numerical unique id of the way
    */
    void setId( int id );
    /**&
    Set whether the way is visible on the map
    
    @param visible True if the way should be visible on the map
    */
    void setVisible( bool visible );
    /**
    Set whether the way is part of a relation. If it is related to
    a relation, it will be rendered on the map as part of that
    relation instead of independently as a way.
    
    @param related True if the node is related to a relation
    */
    void setRelated( bool related );
    
    /**
    Get the unique id of the way
    
    @return The unique id of the way
    */
    int id();
    /**
    Get whether the way is shown on the map
    
    @return True if the way is visible
    */
    bool visible();
    /**
    Get whether the way is related to a relation
    
    @return True if the way is related to a relation
    */
    bool related();
    
    /**
    Paint the way using the provided QPainter
    
    @param painter The QPainter to use to draw the map
    */
    void paint( QPainter* painter, double minlat, double minlon, int zoomMultiplier );
    
  private:
    //Taken straight from XML
    int m_id;
    bool m_visible;
    //True if part of a relation (i.e. if false, then road)
    //TODO: Check if no relation does = road (maybe relations can be roads too?)
    bool m_related;
    //The nodes that make up the way
    QList<OSMNode*> m_nodes;
    
};

#endif