#ifndef MERCATOR_H
#define MERCATOR_H

#include <math.h>
#include <QPoint>

/**
The Mercator class provides a number of static functinos for converting
between degrees (latitude and longitude) and coordinates (x and y) for
display on a map, using thte Guidermannian function.
*/
class Mercator
{
  public:
    
    //Mercator
    //static const double PI = 3.141592;
    //Plate carree
    //static const double LAT1 = 52; //Standard parallels
    
    /**
    Converts longitude to an x coordinate
    
    @param lon The longitude of the point to be converted
    
    @return The x coordinate for use in drawing a map
    */
    static double LonToX( double lon )
    {
      //No projection
      return lon;
      //Mercator
      //return lon;
      //Plate carree
      //return lon * ( 0 - cos( LAT1 ) );
    }
    
    /**
    Converts an x coordinate to longditude
    
    @param x The x coordinate of the point to be converted
    
    @return The longitude of the point drawn on the map
    */
    static double XToLon( double x )
    {
      //No projection
      return x;
      //Mercator
      //return x;
      //Plate carree
      //return x / cos( LAT1 );
    }
    
    /**
    Converts latitude to a y coordinate
    
    @param lat The latitude of the point to be converted
    
    @return The y coordinate for use in drawing a map
    */
    static double LatToY( double lat )
    {
      //No projection
      return lat;
      //Mercator
      //return log( tan ( ( PI / 4 ) + ( lat / 2 ) ) );
      //Plate carree
      //return lat;
    }
    
    /**
    Converts a y coordinate to latditude
    
    @param y The y coordinate of the point to be converted
    
    @return The latitude of the point drawn on the map
    */
    static double YToLat( double y )
    {
      //No projection
      return y;
      //Mercator
      //return atan( sinh( y ) );
      //Plate carree
      //return y;
    }
};

#endif