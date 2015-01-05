/** Author : Paul TREHIOU & Victor SENE
 *  Date : November 2014
 **/
#ifndef __POLYGON_H__
#define __POLYGON_H__


#include <stdlib.h>
#include <stdio.h>
#include <bool.h>
#include <string.h>
#include <math.h>

typedef enum{
	INSIDE = 0,
	OUTSIDE = 1,
	INTERSECT = 2,
	ENCLOSING = 3,
	EQUAL = 4
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
 * Decalration of vector with his  x and y components
 * We now that it's maybe useless with the existance of Point but it's better to make a difference between this two structures of data
 **/
typedef struct {

	double x;
	double y;
}Vector;

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
 * Function wich add a point at a given place in an existing polygon
 * inpoly - Polygon
 * inpoint - Point
 * index - interger wich give the place where the point need to be placed
 * Return a Polygon
 **/
Polygon addPoint(Polygon inpoly, Point inpoint, int index);

/**
 * Function wich add a point at the end of an existing polygon
 * inpoly - Polygon
 * inpoint - Point
 * return a new polygon
 */
Polygon addTail(Polygon inpoly, Point inpoint);

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
 * Function wich return the convex hull of a polygon. Warning ! It works only if the polygon is turning to the left (this is because we didn't manage to sort properly the polygon)
 * inpoly - Polygon
 * Return outpoly
 **/
Polygon convexhullPolygon(Polygon inpoly);

/**
 * Function wich returns a Status enumeration type that could take the following values :
 *	- INSIDE if the second polygon is fully inside the first one
 *	- OUTSIDE if the second polygon is fully outside the first one
 *	- INTERSECT if the second polygon is partially inside/outside the first one, in other words intersecting the second one
 *	- ENCLOSING if the first polygon is fully in
 *
 * Polygon poly1, poly2
 * Return out
 **/
Status containsPolygon (Polygon poly1, Polygon poly2);

/**
 * Function wich extend a polygon in proportion of the given factor
 * inpoly - Polygon
 * factor - float
 * Return a Polygon
 **/
Polygon scalePolygon(Polygon inpoly, float factor);

/**
 * Function wich translate a polygon from P1 to P2
 * P1, P2 - Point
 * Return a Polygon
 * /!\ the translation is from P1 to P2
 **/
Polygon translatePolygon(Polygon inpoly, Point P1, Point P2);

/**
 * Function wich compute the central symmetry of  a specified polygon according to a reference point
 * inpoly - Polygon
 * inpoint - reference Point
 * Return a Polygon
 **/
Polygon centralSymmetry(Polygon inpoly, Point inpoint);

/**
 * Procedure wich print coordinates of a point
 * inpoint - Point
 **/
void printPoint(Point inpoint);

/**
 * Procedure wich print coordinates of all points in a Polygon
 * inpoly - Polygon
 **/
void printPolygon(Polygon inpoly);

/**
 * This function is like printPolygon but it's a function
 * inpoly - Polygon
 * Return a char* (string)
 **/
char* toString(Polygon inpoly);

/**
 * This function return the rotation of a given polygon by an angle and a point
 * inpoly - Polygon
 * inpoint - Point
 * angle - double
 * Return a Polygon
 **/
Polygon rotatePolygon(Polygon inpoly, Point inpoint, double angle);

#endif /*__POLYGON_H__*/

