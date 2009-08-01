#include <QDebug>

#include <QApplication>
#include <QtSql>


int main( int argc, char** argv )
{  
  QApplication app( argc, argv );
  
  OSMDatabase::open( "localhost", "osmsatnav", "root", "br88root" );
  
  
  
  //app.exec();
  
}