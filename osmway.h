#ifndef OSMWAY_H
#define OSMWAY_H

#include "osmtaggable.h"

class OSMNode;

class OSMWay: public OSMTaggable
{
  public:
    OSMWay();
    OSMWay( int id, bool visible );
    
    void addNode( OSMNode* node );
    QList<OSMNode*> nodes();
    
    void setId( int id );
    void setVisible( bool visible );
    void setRelated( bool related );
    
    int id();
    bool visible();
    bool related();
    
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