#include <QString>

class OSMMap;

class OSMDatabase
{
  public:
    static bool open( QString host, QString name, QString user, QString pass );
    static bool isOpen();
    static void writeMap( OSMMap* map );
};