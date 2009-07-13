#include "osmtag.h"

OSMTag::OSMTag()
{
}

OSMTag::OSMTag( QString a, QString b )
{
  m_name = a;
  m_value = b;
}

OSMTag::OSMTag( QXmlStreamReader &xml )
{
  readTag( xml );
}

void OSMTag::setName( QString name ) 
{
  m_name = name; 
}

void OSMTag::setValue( QString value ) 
{
  m_value = value; 
}

QString OSMTag::name() 
{
  return m_name; 
}

QString OSMTag::value() 
{
  return m_value; 
}

OSMTag OSMTag::readTag( QXmlStreamReader &xml ) 
{
  m_name = xml.attributes().value( "k" ).toString();
  m_value = xml.attributes().value( "v" ).toString();
  
  return *this;
}