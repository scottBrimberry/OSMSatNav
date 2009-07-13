#ifndef OSMRELATIONMEMBER_H
#define OSMRELATIONMEMBER_H  

#include <QXmlStreamReader>

class OSMRelationMember
{
  public:
    enum Type
    {
      Node,
      Way
    };
    
    OSMRelationMember();
    OSMRelationMember( Type a, int b );
    OSMRelationMember( QXmlStreamReader &xml );
    
    void setType( Type type );
    void setRef( int ref );
    
    Type type();
    int ref();
    
    OSMRelationMember readMember( QXmlStreamReader &xml );
    
  private:
    Type m_type;
    int m_ref;
};

#endif