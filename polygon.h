/** Author : Paul TREHIOU & Victor SENE
 *  Date : November 2014
 **/

#include <stdlib.h>
#include <stdio.h>
 
/**
 * Declaration Point structure
 * x - real wich is the abscisse of the point
 * y - real wich is the ordinate of the point
 */
typedef struct
{
	double x;
 	double y;
}Point;

/**
 * Declaration of the Element structure
 * value - value of the point of the current element of the polygon
 * next - pointer on the next element
 * previous - pointer on the previous element
 */
typedef struct pointelem{

	Point value;
	struct pointelem* next;
	struct pointelem* previous;

}PointElement;

/**
 * Declaration of the Polygon
 */
typedef PointElement* Polygon;

/**
 * Function wich create a point with a specified abscisse and ordinate
 * abscisse - real
 * ordinate - real
 * return a new point
 */
Point createPoint(double abscisse, double ordinate);

/**
 * Function wich create a new empty Polygon
 * return the new empty polygon
 */
Polygon createPolygon();

/**
 * Function wich add a point at the end of an existing polygon
 * inpoly - Polygon
 * inpoint - Point
 * return a new polygon
 */
Polygon addPoint(Polygon inpoly, Point inpoint);
