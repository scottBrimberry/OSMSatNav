#include <QtGui>
#include <QtSql>

#include "database.h"
#include "osmmap.h"
#include "osmxml.h"


int main( int argc, char** argv )
{  
  QApplication app( argc, argv );
  
  OSMDatabase::open( "localhost", "osmsatnav", "root", "br88root" );
  
  //app.exec();
  
}