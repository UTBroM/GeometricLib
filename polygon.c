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
 * Function wich add a point at the end of an existing polygon
 * inpoly - Polygon
 * inpoint - Point
 * newelem - new Point in the Polygon
 * return a new polygon
 */
Polygon addPoint(Polygon inpoly, Point inpoint)
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
	/*short place = 0;*/
	int i = 0;

	for(i=0;i<=inpoly.size;i++)
	{

		inter = NULL;

		inter = segmentsCross(inpoly.head->value,inpoly.head->next->value,inpoint,createPoint(max(inpoly.head->value.x,inpoly.head->next->value.x)+10,inpoint.y)); /*Return the intersection of the current segment and a virtual horizontally segment draw from the testing point*/

		if(inter != NULL){

			/*Exclude the case when the virtual segment go on a point*/
			if(((inter->value.x != inpoly.head->value.x ) || (inter->value.y != inpoly.head->value.y )) && (inpoint.x < inter->value.x)){

				out = !out;

			}

		}





		/*if((inpoly.head->value.y < inpoint.y))
		{

			if(inpoly.head->value.x > inpoint.x && place==1){out = !out;}
			place = -1;

		}
		else if(inpoly.head->value.y >= inpoint.y)
		{

			if(inpoly.head->value.x > inpoint.x && place==-1){out = !out;}
			place = 1;

		}*/

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

	d = (p1.x-p2.x)*(p3.y-p4.y) - (p1.y-p2.y)*(p3.x-p4.x);
	if(d == 0){free(out);return NULL;}

	xi = ((p3.x-p4.x)*(p1.x*p2.y-p1.y*p2.x)-(p1.x-p2.x)*(p3.x*p4.y-p3.y*p4.x))/d;
	yi = ((p3.y-p4.y)*(p1.x*p2.y-p1.y*p2.x)-(p1.y-p2.y)*(p3.x*p4.y-p3.y*p4.x))/d;

	if(((xi < p1.x && xi < p2.x) || (xi > p1.x && xi > p2.x)) || ((yi < p1.y && yi < p2.y) || (yi > p1.y && yi > p2.y))){

		free(out);
		return NULL;

	}
	if(((xi < p3.x && xi < p4.x) || (xi > p3.x && xi > p4.x)) || ((yi < p3.y && yi < p4.y) || (yi > p3.y && yi > p4.y))){

		free(out);
		return NULL;

	}

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

