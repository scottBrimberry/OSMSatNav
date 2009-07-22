#ifndef OSMTAG_H
#define OSMTAG_H

#include <QString>
#include <QXmlStreamReader>

class OSMTag
{
public:
    OSMTag();
    OSMTag( QString a, QString b );
    OSMTag( QXmlStreamReader &xml );

    void setName( QString name );
    void setValue( QString value );

    QString name();
    QString value();

    OSMTag readTag( QXmlStreamReader &xml );

private:
    QString m_name;
    QString m_value;
};

#endif
