/** Author : Paul TREHIOU & Victor SENE
 *  Date : November 2014
 **/

#include <polygon.h>

/**
 * Function wich create a point with a specified abscisse and ordinate
 * abscisse - real
 * ordinate - real
 * return a new point
 **/
Point createPoint(double abscisse, double ordinate){

	Point newpoint;
	newpoint.x = abscisse;
	newpoint.y = ordinate;
	return newpoint;

}

/**
 * Function wich create a new empty polygon
 * return the new empty polygon
 **/
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
	PointElement* newelem = NULL; /*Create the new element*/

	/*Replication of the old polygon*/
	newpoly.head = inpoly.head;
	newpoly.size = inpoly.size;

	/*Allocation of the memory for the new element*/
	newelem=(PointElement*)malloc(sizeof(PointElement));
	newelem->value = inpoint;

	/*This loop find the element just before the place we want to add the new point*/
	for (i=0; i<index-2; i++)
	{
		newpoly.head = newpoly.head->next;
	}

	/*Linking of the different elements*/
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
 **/
Polygon addTail(Polygon inpoly, Point inpoint)
{

	Polygon newpoly;
	PointElement* newelem = NULL;

	/*Same behavior as addPoint function*/
	newpoly.head = inpoly.head;
	newpoly.size = inpoly.size;
	newelem=(PointElement*)malloc(sizeof(PointElement));
	newelem->value = inpoint;

	/*Case when the polygon is empty*/
	if(inpoly.head==NULL)
	{

		newpoly.head=newelem;
		newpoly.head->next=newpoly.head;
		newpoly.head->prev=newpoly.head;

	}
	else /*we link all the elements together*/
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
 **/
Polygon removePoint(Polygon inpoly, int index)
{

	int i;
	Polygon newpoly;

	/*Replication of the polygon*/
	newpoly.head = inpoly.head;
	newpoly.size = inpoly.size;

	/*We look for place of the element we want to remove*/
	for(i=0;i<index-1;i++)
	{

		newpoly.head = newpoly.head->next;

	}

	/*We link all the elements to bypass the element we want to throw. newpoly is used to save the adress of the old element in order to free the momory later*/
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
 **/
BOOL containsPoint(Polygon inpoly, Point inpoint)
{

	BOOL out = FALSE;
	Intersection* inter = NULL;
	int i = 0;

	for(i=0;i<=inpoly.size;i++)
	{

		inter = NULL;
		/*Return the intersection of the current segment and a virtual horizontally segment draw from the testing point*/
		inter = segmentsCross(inpoly.head->value,inpoly.head->next->value,inpoint,createPoint(max(inpoly.head->value.x,inpoly.head->next->value.x)+10,inpoint.y));

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
 * /!\ p1 and p2 constitue the first segment, and p3, p4 the second
 * /!\ This function return NULL if a segment of a polygon are mingled
 **/
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
 **/
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

	/*Case when the polygon is bigger than one element*/
 	if (inpoly.size>1){

		inpoly.head->prev = tail->prev;
		tail->prev->next = inpoly.head;
		inpoly.size--;
		free(tail);

 	}
	/*Case when the polygon is empty or contain 1 element*/
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
 *  - EQUAL if polygons are strictly the same
 * 
 * Polygon poly1, poly2
 * Return out
 **/
Status containsPolygon (Polygon poly1, Polygon poly2)
{

	int i=0,j=0;
	BOOL inter=FALSE;

	/*We first test if both polygons are equal*/
	if(poly1.size == poly2.size){

		/*Check if the number of points is equal*/
		for(i=0;i<poly1.size;i++){

			/*Check if all the points are equal*/
			if(poly1.head->value.x == poly2.head->value.x && poly1.head->value.y == poly2.head->value.y){

				poly1.head = poly1.head->next;
				poly2.head = poly2.head->next;

			}
			else{

				return EQUAL;

			}

		}

	}

	i=0;

	/*These 2 loops go trough each polygon and check if they are any intersections*/
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

	/*Depending of the intersection we return the corresponding state*/
	if(inter){return INTERSECT;} /*If there is any intersection the two polygons intersects*/
	else if(containsPoint(poly2,poly1.head->value)){return ENCLOSING;} /*If any random point of the first polygon is contained then it is enclosing*/
	else if(containsPoint(poly1,poly2.head->value)){return INSIDE;} /*If any random point of the second polygon is contained then it is inside*/
	else{return OUTSIDE;} /*If anything else is false it is outside*/

}

/**
 * Function wich extend a polygon in proportion of the given factor
 * inpoly - Polygon
 * factor - float
 * Return the modified Polygon (/!\ the precedent polygon is deleted)
 **/
Polygon scalePolygon(Polygon inpoly, float factor)
{
	int i;

	/*Each coordinate is multiplicated by the factor resulting in a scaled polygon*/
	for (i = 0; i < inpoly.size; i++)
	{
		inpoly.head = inpoly.head->next;

		inpoly.head->value.x = factor * inpoly.head->value.x;
		inpoly.head->value.y = factor * inpoly.head->value.y;
	}

	return inpoly;
}

/**
 * Function wich translate a polygon from P1 to P2
 * P1, P2 - Point
 * Return a Polygon
 * /!\ the translation is from P1 to P2
 **/
Polygon translatePolygon(Polygon inpoly, Point P1, Point P2)
{
	Vector P1toP2;
	int i;

	P1toP2.x = P2.x - P1.x;
	P1toP2.y = P2.y - P1.y;
	
	for (i=0; i< inpoly.size; i++)
	{
		/*Add the coordinate of the translation vector to each point of the polygon*/
		inpoly.head->value.x = inpoly.head->value.x + P1toP2.x;
		inpoly.head->value.y = inpoly.head->value.y + P1toP2.y;

		inpoly.head = inpoly.head->next;
	}
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
	double angle;
	PointElement *min, *minangle;

	/*Find the point with the lowest y-coordinate and if there is multiple points with the same y-coordinate the one with the lowest x-coordinate, it would be the first point*/

	min = inpoly.head;
	for(i=0;i<inpoly.size;i++)
	{

		inpoly.head = inpoly.head->next;

		if(inpoly.head->value.y <= min->value.y){

			if(inpoly.head->value.y != min->value.y || inpoly.head->value.x < min->value.x){

				min = inpoly.head;

			}

		}

	}

	/*Copy the value of this point in the new polygon*/
	outpoly = addTail(outpoly, min->value);

	/*Set the head of inpoly to the next point of min*/

	inpoly.head = min->next;

	/*The second point is the one who make the lowest angle with the x-axis */

	angle = atan2 (inpoly.head->value.y - min->value.y,inpoly.head->value.x -  min->value.x);
	minangle = inpoly.head;

	for(i=0;i<inpoly.size-1;i++)
	{

		inpoly.head = inpoly.head->next;

		if(atan2 ( min->value.y - inpoly.head->value.y, min->value.x - inpoly.head->value.x) < angle){

			minangle = inpoly.head;

		}

	}

	/*Copy the value of this point in the new polygon*/
	outpoly = addTail(outpoly, minangle->value);

	/*Remove these elements in inpoly*/
	inpoly.head = min->prev;
	removePoint(inpoly, 2);
	inpoly.head = minangle->prev;
	removePoint(inpoly, 2);

	for (i = 3; i < inpoly.size; i++)
	{

		inpoly.head = inpoly.head->next;

		/*Vectorial product of the last segments of outpoly, the sign should be positive to continue (it would mean that the polygon turn always in the same direction)*/

		while (outpoly.size >= 2 && ((outpoly.head->next->value.x - outpoly.head->value.x) * (inpoly.head->value.y - outpoly.head->next->value.y) - (inpoly.head->value.x - outpoly.head->next->value.x) * (outpoly.head->next->value.y - outpoly.head->value.y) < 0))
		{

			/*If the shape turn in the wrong direction we delete the last point and test again with the previous point*/
			outpoly.head = outpoly.head->prev;
			outpoly = removePoint(outpoly,3);

		}

		/*if it's OK we go trough the next segment*/
		outpoly = addPoint(outpoly, inpoly.head->value, 3);
		outpoly.head = outpoly.head->next;

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

	/*Go trough all points and calculate the symmetry of each*/
	for (i=0; i < inpoly.size; i++)
	{
		oldx = inpoly.head->value.x;
		oldy = inpoly.head->value.y;
		newx = 2 * inpoint.x - oldx;
		newy = 2 * inpoint.y - oldy;

		newpoint = createPoint(newx,newy);
		outpoly = addTail(outpoly, newpoint);

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
	for (i=1; i < inpoly.size; i++)
	{
		printPoint(inpoly.head->value);
		printf(",");

		inpoly.head = inpoly.head->next;
	}
	printPoint(inpoly.head->value);
	printf("]\n");
}

/**
 * This function is like printPolygon but it's a function
 * inpoly - Polygon
 * Return a char* (string)
 * /!\ We have a buffer and we can't manage double wich are greater than the lenght of the BUFFER. That's can be improve.
 **/
char* toString(Polygon inpoly)
{
	char* string;
	char BUFFER[1000];
	double x, y;
	int i;

	string = (char*)malloc(sizeof(char)*2);
	string[0] = '[';
	string[1] = '\0';

	for (i=1; i<inpoly.size; i++)
	{
		x = inpoly.head->value.x;
		y = inpoly.head->value.y;

		/*Reallocation of memory to adapt it according to the lenght of the coordinates*/
		string = realloc(string, sizeof(char)*(strlen(string)+strlen(BUFFER)+1));

		sprintf(BUFFER, "[%.2f,%.2f],", x, y);
		strcat(string,BUFFER);
		inpoly.head = inpoly.head->next;
	}
	/*Same instruction than in the loop but we want to change the end of the string*/
	x = inpoly.head->value.x;
	y = inpoly.head->value.y;

	string = realloc(string, sizeof(char)*(strlen(string)+strlen(BUFFER)+1));

	sprintf(BUFFER, "[%.2f,%.2f]]", x, y);
	strcat(string,BUFFER);
	
	return string;
}

/**
 * This function return the rotation of a given polygon by an angle and a point
 * inpoly - Polygon
 * inpoint - Point
 * angle - double
 * Return a Polygon
 **/
Polygon rotatePolygon(Polygon inpoly, Point inpoint, double angle)
{

	double xref = inpoint.x;
	double yref = inpoint.y;
	double x, y, module, arg;
	int i;

	/*Go through ech point and compute the rotation*/
	for(i=1;i<=inpoly.size;i++){

		/*compute the distance between the reference point and the current point on x and y*/
		x = inpoly.head->value.x - xref;
		y = inpoly.head->value.y - yref;

		/*We use complex numbers because the module stay the same and it's easy to change the argument and fall back to coordinates*/
		module = sqrt(x*x + y*y); /*Computation of the module*/
		arg = atan2(y,x); /*C function that compute the argument in radian of a given complex of the form x+i*y*/

		arg = arg + angle; /*Rotation of the current point*/

		/*Computation of the new x and y*/
		inpoly.head->value.x=cos(arg)*module + xref;
		inpoly.head->value.y=sin(arg)*module + yref;

		inpoly.head = inpoly.head->next;

	}

	return inpoly;

}

/**
 * This function return the union of two Polygons
 * poly1 - Polygon
 * poly2 - Polygon
 * Return a Polygon
 **/
Polygon unionPolygons(Polygon poly1, Polygon poly2)
{

	int i;
	Polygon outpoly = createPolygon();

	/*First add all points of the both polygon in a new one*/

	for(i=0;i<poly1.size;i++){

		addTail(outpoly, poly1.head->value);
		poly1.head = poly1.head->next;

	}

	for(i=1;poly2.size;i++){

		addTail(outpoly, poly2.head->value);
		poly2.head = poly2.head->next;

	}

	/*Compute the convex hull of this new polygon*/

	outpoly = convexhullPolygon(outpoly);

	return outpoly;

}
