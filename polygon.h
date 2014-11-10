/** Author : Paul TREHIOU & Victor SENE
 *  Date : November 2014
 **/

/**
 * Declaration Point structure
 * x - real wich is the abscisse of the point
 * y - real wich is the ordinate of the point
 */

 typedef struct
 {
 	float x;
 	float y;
 }Point;

/**
 * Function wich create a point with a specified abscisse and ordinate
 * abscisse - real
 * ordinate - real
 * return a new point
 */

createPoint(float abscisse, float ordinate);

typedef struct pointelem{

	Point value;
	pointelem* next;
	pointelem* before;

}PointElement;

typedef PointElement* Polygon;
