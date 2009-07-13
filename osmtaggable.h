#ifndef OSMTAGGABLE_H
#define OSMTAGGABLE_H

#include <QList>
#include <QXmlStreamReader>

#include "osmtag.h"

class OSMTaggable
{
  public:
    OSMTaggable();
    
    void addTag( QString name, QString value );
    
    void addTag( QXmlStreamReader &xml );
    
    bool hasTag( QString name, QString &value );
    
    QList<OSMTag> tags();
    
  private:
    //Tags
    QList<OSMTag> m_tags;
};

#endif