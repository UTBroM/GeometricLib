/** Author : Paul TREHIOU & Victor SENE
 *  Date : November 2014
 **/
#ifndef __POLYGON_H__
#define __POLYGON_H__


#include <stdlib.h>
#include <stdio.h>
#include <bool.h>

typedef enum{
	INSIDE = 0,
	OUTSIDE = 1,
	INTERSECT = 2,
	ENCLOSING = 3
}Status;

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
	Point a1; /*First point of the segment 1*/
	Point a2; /*Second point of the segment 1*/
	Point b1; /*First point of the segment 2*/
	Point b2; /*Second point of the segment 2*/

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
BOOL containsPoint(Polygon inpoly, Point inpoint);

/**
 * Function wich return the intersection between two segments NULL otherwise
 * Point p1, p2, p3, p4
 * Return an pointer on an intersection
 */
Intersection* segmentsCross(Point p1, Point p2, Point p3, Point p4);

/**
 * Function wich return the maximum value of 2 double
 * double a, b
 * Return the maximum
 */
double max(double a, double b);

/**
 * Function wich remove the last element of a polygon
 * Polygon inpoly
 * Return inpoly
 **/
Polygon removeTail (Polygon inpoly);

/**
 * Function wich return the convex hull of a polygon
 * Polygon inpoly
 * Return outpoly
 **/
Polygon convexhullPolygon(Polygon inpoly);

#endif /*__POLYGON_H__*/

