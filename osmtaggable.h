#ifndef OSMTAGGABLE_H
#define OSMTAGGABLE_H

#include <QList>
#include <QXmlStreamReader>

#include "osmtag.h"

/**
This class is designed to be a superclass of objects that represent taggable
objects within a map, such as nodes, ways and relations. It saves having to
implement tag handling capabilities in each class that requires it.
*/
class OSMTaggable
{
public:
    /**
    Create an empty OSMTaggable object
    */
    OSMTaggable();

    /**
    Add a tag to the object. The name and value are provided as arguments.

    @param name The name, or key, of the tag
    @param value The value of the tag
    */
    void addTag( QString name, QString value );

    /**
    Add a tag to the object. The tag is read from the QXMLStreamReader object
    provided. The xml reader should be positioned at a tag start element.
    (i.e. xml.isStartElement() && xml.name() == "tag" )

    @param xml A QXMLStreamReader object at the correct position
    */
    void addTag( QXmlStreamReader &xml );

    /**
    This function returns true if the object has a tag with the given name, and
    the value of the tag is written to value.

    @param name The name of the tag to check for
    @param value The value of the found tag is written to this QString variable

    @return True if the tag is found, false otherwise
    */
    bool hasTag( QString name, QString &value );

    /**
    Returns a QList of all the OSMTag objects within the object.

    @return A QList<OSMTag> containing all the tags in the object.
    */
    QList<OSMTag> tags();

private:
    //Tags
    QList<OSMTag> m_tags;
};

#endif
