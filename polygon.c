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
		newpoly.head->previous=newpoly.head;

	}
	else
	{

		newelem->next = inpoly.head;
		newelem->previous = inpoly.head->previous;
		newpoly.head->previous->next = newelem;
		newpoly.head->previous = newelem;

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

	newpoly.head->previous->next = newpoly.head->next;
	newpoly.head->next->previous = newpoly.head->previous;

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
boolean containsPoint(Polygon inpoly, Point inpoint)
{

	boolean out = FALSE;
	short place = 0;
	int i = 0;

	for(i=0;i<=inpoly.size;i++)
	{

		if((inpoly.head->value.y < inpoint.y))
		{

			if(inpoly.head->value.x > inpoint.x && place==1){out = !out;}
			place = -1;

		}
		else if(inpoly.head->value.y > inpoint.y)
		{

			if(inpoly.head->value.x > inpoint.x && place==-1){out = !out;}
			place = 1;

		}
		else if(inpoly.head->value.y == inpoint.y)
		{

			if(inpoly.head->next->value.y > inpoint.y && inpoly.head->previous->value.y < inpoint.y)
			{

				if(inpoly.head->value.x > inpoint.x && place==-1){out = !out;}
				place = 1;

			}
			else if(inpoly.head->next->value.y < inpoint.y && inpoly.head->previous->value.y > inpoint.y)
			{

				if(inpoly.head->value.x > inpoint.x && place==1){out = !out;}
				place = -1;

			}

		}

	inpoly.head = inpoly.head->next;

	}

	return out;

}

