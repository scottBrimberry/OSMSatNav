#include <QString>

static class OSMDatabase
{
  public:
    bool open( QString host, QString name, QString user, QString pass );
    bool isOpen();
    void writeMap( OSMMap* map );
    
  private:
    bool m_open = false;
}