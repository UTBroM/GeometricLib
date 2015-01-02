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

	Polygon newpoly;
	newpoly.head = NULL;
	newpoly.size = 0;
	return newpoly;

}

/**
 * Function wich add a point at a given place in an existing polygon
 * inpoly - Polygon
 * inpoint - Point
 * index - interger wich give the place where the point need to be placed
 * Return a Polygon
 **/
Polygon addPoint(Polygon inpoly, Point inpoint, int index)
{
	int i;
	Polygon newpoly;
	PointElement* newelem = NULL;

	newpoly.head = inpoly.head;
	newpoly.size = inpoly.size;
	
	newelem=(PointElement*)malloc(sizeof(PointElement));
	newelem->value = inpoint;

	for (i=0; i<index-2; i++)
	{
		newpoly.head = newpoly.head->next;
	}
	newelem->next = newpoly.head->next;
	newpoly.head->next->prev = newelem;
	newpoly.head->next = newelem;
	newelem->prev = newpoly.head;

	inpoly.size++;

	return inpoly;
}

/**
 * Function wich add a point at the end of an existing polygon
 * inpoly - Polygon
 * inpoint - Point
 * newelem - new Point in the Polygon
 * return a new polygon
 */
Polygon addTail(Polygon inpoly, Point inpoint)
{

	Polygon newpoly;
	PointElement* newelem = NULL;

	newpoly.head = inpoly.head;
	newpoly.size = inpoly.size;
	newelem=(PointElement*)malloc(sizeof(PointElement));
	newelem->value = inpoint;

	if(inpoly.head==NULL)
	{

		newpoly.head=newelem;
		newpoly.head->next=newpoly.head;
		newpoly.head->prev=newpoly.head;

	}
	else
	{

		newelem->next = inpoly.head;
		newelem->prev = inpoly.head->prev;
		newpoly.head->prev->next = newelem;
		newpoly.head->prev = newelem;

	}

	newpoly.size++;

	return newpoly;

}

/**
 * Function wich remove a point at a given place in an existing polygon
 * inpoly - Polygon
 * index - int
 * return a new polygon
 */
Polygon removePoint(Polygon inpoly, int index)
{

	int i;
	Polygon newpoly;
	newpoly.head = inpoly.head;
	newpoly.size = inpoly.size;

	for(i=0;i<index-1;i++)
	{

		newpoly.head = newpoly.head->next;

	}

	newpoly.head->prev->next = newpoly.head->next;
	newpoly.head->next->prev = newpoly.head->prev;

	free(newpoly.head);

	inpoly.size--;

	return inpoly;

}

/**
 * Function wich return true if a point is contained into a polygon, false otherwise
 * inpoly - Polygon
 * inpoint - Point
 * return a boolean
 */
BOOL containsPoint(Polygon inpoly, Point inpoint)
{

	BOOL out = FALSE;
	Intersection* inter = NULL;
	int i = 0;

	for(i=0;i<=inpoly.size;i++)
	{

		inter = NULL;

		inter = segmentsCross(inpoly.head->value,inpoly.head->next->value,inpoint,createPoint(max(inpoly.head->value.x,inpoly.head->next->value.x)+10,inpoint.y)); /*Return the intersection of the current segment and a virtual horizontally segment draw from the testing point*/

		if(inter != NULL){

			/*Exclude the case when the virtual segment go on one of the two points of a segment of the polygon (otherwise the point would be counted 2 time)*/
			if(((inter->value.x != inpoly.head->value.x ) || (inter->value.y != inpoly.head->value.y )) && (inpoint.x < inter->value.x)){

				out = !out;

			}

		}

	inpoly.head = inpoly.head->next;

	}

	return out;

}

/**
 * Function wich return the intersection between two segments NULL otherwise
 * Point p1, p2, p3, p4
 * Return an pointer on an intersection
 */
Intersection* segmentsCross(Point p1, Point p2, Point p3, Point p4)
{

	double d, xi, yi;
	Intersection* out;
	out = (Intersection*)malloc(sizeof(Intersection));

	d = (p1.x-p2.x)*(p3.y-p4.y) - (p1.y-p2.y)*(p3.x-p4.x); /*Temporary variable that store a calculated real*/
	if(d == 0){free(out);return NULL;} /*If this variable is 0 there aren't any intersections because the two right are parallel*/

	xi = ((p3.x-p4.x)*(p1.x*p2.y-p1.y*p2.x)-(p1.x-p2.x)*(p3.x*p4.y-p3.y*p4.x))/d; /*Coordinates of the intersection*/
	yi = ((p3.y-p4.y)*(p1.x*p2.y-p1.y*p2.x)-(p1.y-p2.y)*(p3.x*p4.y-p3.y*p4.x))/d;

	/*Check if the intersection is effectively in the two segments*/
	if(((xi < p1.x && xi < p2.x) || (xi > p1.x && xi > p2.x)) || ((yi < p1.y && yi < p2.y) || (yi > p1.y && yi > p2.y))){

		free(out);
		return NULL;

	}
	if(((xi < p3.x && xi < p4.x) || (xi > p3.x && xi > p4.x)) || ((yi < p3.y && yi < p4.y) || (yi > p3.y && yi > p4.y))){

		free(out);
		return NULL;

	}

	/*Store all the value in "out"*/
	out->value.x = xi;
	out->value.y = yi;

	out->a1 = p1;
	out->a2 = p2;
	out->b1 = p3;
	out->b2 = p4;


	return out;

}

/**
 * Function wich return the maximum value of 2 double
 * double a, b
 * Return the maximum
 */
double max(double a, double b)
{

	if(a>b){

		return a;

	}
	else{

		return b;

	}

}

/**
 * Function wich remove the last element of a polygon
 * Polygon inpoly
 * Return inpoly
 **/
Polygon removeTail (Polygon inpoly)
{

	PointElement* tail = inpoly.head->prev;

 	if (inpoly.size>1){

		inpoly.head->prev = tail->prev;
		tail->prev->next = inpoly.head;
		inpoly.size--;
		free(tail);

 	}
	else{

		inpoly.head = NULL;
		inpoly.size = 0;

	}

 	return inpoly;
}

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
Status containsPolygon (Polygon poly1, Polygon poly2)
{

	int i=0,j=0;
	BOOL inter=FALSE;

	while(i<poly1.size && !inter){

	j=0;

		while(j<poly2.size && !inter){

			if(segmentsCross(poly1.head->value, poly1.head->next->value, poly2.head->value, poly2.head->next->value) != NULL){

				inter=TRUE;

			}

		j++;
		poly2.head = poly2.head->next;

		}

	i++;
	poly1.head = poly1.head->next;

	}

	if(inter){return INTERSECT;}
	else if(containsPoint(poly2,poly1.head->value)){return ENCLOSING;}
	else if(containsPoint(poly1,poly2.head->value)){return INSIDE;}
	else{return OUTSIDE;}

}

/**
 * Function wich extend a polygon in proportion of the given factor
 * inpoly - Polygon
 * factor - float
 * Return a Polygon
 **/
Polygon scalePolygon(Polygon inpoly, float factor)
{
	PointElement* referencePoint;
	int i;
	referencePoint = inpoly.head;

	for (i = 1; i < inpoly.size - 1; i++)
	{
		inpoly.head = inpoly.head->next;

		inpoly.head->value.x = inpoly.head->value.x + factor * ((inpoly.head->value.x)-(referencePoint->value.x));
		inpoly.head->value.y = inpoly.head->value.y + factor * ((inpoly.head->value.y)-(referencePoint->value.y));
	}

	inpoly.head = referencePoint;

	return inpoly;
}

/**
 * Function wich return the convex hull of a polygon
 * inpoly - Polygon 
 * Return outpoly
 **/
Polygon convexhullPolygon(Polygon inpoly)
{
	Polygon outpoly = createPolygon();
	int i;

	addTail(outpoly, inpoly.head->value);
	inpoly.head = inpoly.head->next;
	addTail(outpoly, inpoly.head->value);

	for (i = 3; i < inpoly.size; i++)
	{
		inpoly.head = inpoly.head->next;

		while (outpoly.size >= 2 && ((outpoly.head->value.y - (outpoly.head->prev->value.x)*(inpoly.head->value.y) - (outpoly.head->prev->value.y) - (inpoly.head->value.x) - (outpoly.head->prev->value.x)*(outpoly.head->value.y) - (outpoly.head->prev->value.y)) <= 0))
		{
			removeTail(outpoly);
		}

		addTail(outpoly, inpoly.head->value);

	}

	return outpoly;

}

/**
 * Function wich compute the central symmetry of  a specified polygon according to a reference point
 * inpoly - Polygon
 * inpoint - reference Point
 * Return a Polygon
 **/
Polygon centralSymmetry(Polygon inpoly, Point inpoint)
{
	Polygon outpoly=createPolygon(outpoly);
	Point newpoint;
	double oldx, oldy, newx, newy;
	int i;

	for (i=1; i < inpoly.size; i++)
	{
		oldx = inpoly.head->value.x;
		oldy = inpoly.head->value.y;
		newx = 2 * inpoint.x - oldx;
		newy = 2 * inpoint.y - oldy;

		newpoint = createPoint(newx,newy);
		addTail(outpoly, newpoint);

		inpoly.head = inpoly.head->next;
	}

	return outpoly;
}

/**
 * Procedure wich print coordinates of a point
 * inpoint - Point
 **/
void printPoint(Point inpoint)
{
	printf("[%.2f,%.2f]", inpoint.x, inpoint.y);
}

/**
 * Procedure wich print coordinates of all points in a Polygon
 * inpoly - Polygon
 **/
void printPolygon(Polygon inpoly)
{
	int i;

	printf("[");
	for (i=1; i < (inpoly.size-1); i++)
	{
		printPoint(inpoly.head->value);
		printf(",");

		inpoly.head = inpoly.head->next;
	}
	printPoint(inpoly.head->value);
	printf("]\n");
}
