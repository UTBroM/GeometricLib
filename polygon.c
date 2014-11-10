/** Author : Paul TREHIOU & Victor SENE
 *  Date : November 2014
 **/
 
#include <polygon.h>

/**
  * Function wich create a point with a specified abscisse and ordinate
  * abscisse - real
  * ordinate - real
  * return a new point
  */
Point createPoint(double abscisse, double ordinate){

	Point newpoint;
	newpoint.x = abscisse;
	newpoint.y = ordinate;
	return newpoint;

}

/**
  * Function wich create a new empty polygon
  * return the new empty polygon
  */

Polygon createPolygon(){

	Polygon newpoly=NULL;
	newpoly = (PointElement*)malloc(sizeof(PointElement));
	newpoly->value=createPoint(0,0);
	newpoly->next=newpoly;
	newpoly->previous=newpoly;
	return newpoly;

}
/**
 * Function wich add a point at the end of an existing polygon
 * inpoly - Polygon
 * inpoint - Point
 * return a new polygon
 */
Polygon addPoint(Polygon inpoly, Point inpoint)
{

	Polygon newpoly = inpoly;
	PointElement* newelem=NULL;
	newelem=(PointElement*)malloc(sizeof(PointElement));
	newelem->value = inpoint;
	newelem->next = inpoly;
	newelem->previous = inpoly->previous;
	newpoly->previous->next = newelem;
	newpoly->previous = newelem;
	return newpoly;

}
