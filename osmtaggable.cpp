#include "osmtaggable.h"

OSMTaggable::OSMTaggable()
{
}

void OSMTaggable::addTag( QString name, QString value )
{
    m_tags.append( OSMTag( name, value ) );
}

void OSMTaggable::addTag( QXmlStreamReader &xml )
{
    m_tags.append( OSMTag( xml ) );
}

bool OSMTaggable::hasTag( QString name, QString &value )
{
    foreach( OSMTag i, m_tags )
    {
        if ( i.name() == name )
        {
            value = i.value();
            return true;
        }
    }

    return false;
}

QList<OSMTag> OSMTaggable::tags()
{
    return m_tags;
}
