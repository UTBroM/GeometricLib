/** Author : Paul TREHIOU & Victor SENE
 *  Date : November 2014
 **/

#include <stdlib.h>
#include <stdio.h>

/*Declaration of the boolean type*/
typedef enum{TRUE=(1==1),FALSE=(1==0)}boolean;
 
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
	struct pointelem* prev;

}PointElement;

/**
 * Declaration of the Polygon
 */
typedef struct {

	PointElement* head;
	int size;

}Polygon;

/**
 * Declaration of the Intersection
 */
typedef struct{

	Point value;
	PointElement* a1; /*First point of the segment 1*/
	PointElement* a2; /*Second point of the segment 1*/
	PointElement* b1; /*First point of the segment 2*/
	PointElement* b2; /*Second point of the segment 2*/

}Intersection;
	

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

/**
 * Function wich remove a point at a given place in an existing polygon
 * inpoly - Polygon
 * index - int
 * return a new polygon
 */
Polygon removePoint(Polygon inpoly, int index);

/**
 * Function wich return true if a point is contained into a polygon, false otherwise
 * inpoly - Polygon
 * inpoint - Point
 * return a boolean
 */
boolean containsPoint(Polygon inpoly, Point inpoint);

