#ifndef OSMXML_H
#define OSMXML_H

#include <QString>

class OSMMap;

/**
This class provides static members for reading from and writing to
OpenStreetMap.org XML files (.osm  files).
*/
class OSMXml
{
  public:
    /**
    Reads the given XML file into an OSMMap object
    
    @param filename The location of the file to read
    @param map A poitner to the OSMMap object to populate with the information from filename
    
    @return True is successful, false otherwise
    */
    static bool readFile( QString filename, OSMMap* map );
    
    /**
    Writes the given OSMMap object to a .osm XML file
    
    @param filename The location of the file to write to
    @param map A pointer to the OSMMap object to write
    
    @return True if successful, false otherwise
    */
    //static bool writeFile( QString filename, OSMMap* map );
};

#endif