#include <polygon.h>


int main(int argc, char* argv[]) {

	int choice, i;
	Polygon lol, polyloutre, convexpoly, biglol, symetriclol;
	Point a, P1, P2, P3, P4, test;
	Status testing;
	Intersection* testlol; 
	double x1, x2, y1, y2, x3, x4, y3, y4;
	char* string;



	printf("################################################################################\n");
	printf("#  ****   *****  ****  *     * ***** ***** *****  *  *****      *     * *****  #\n");
	printf("# *    *  *     *    * * *  ** *       *   *    * * *           *     * *    * #\n");
	printf("# *       ***   *    * *  *  * ***     *   ** *   * *           *     * * ***  #\n");
	printf("# *   **  *     *    * *     * *       *   *   *  * *           *     * *    * #\n");
	printf("#   ****  *****  ****  *     * *****   *   *    * *  *****      ***** * *****  #\n");
	printf("################################################################################\n");


	printf("1. Create a Point and display it\n");
	printf("2. Create a Polygon add Point in it and see the result\n");
	printf("5. removePoint\n");
	printf("6. removeTail\n");
	printf("7. containsPoint\n");
	printf("8. containsPolygon\n");
	printf("9. translatePolygon\n");
	printf("10. rotatePolygon\n");
	printf("11. scalePolygon\n");
	printf("12. centralSymmetry\n");
	printf("13. segmentsCross\n");
	printf("14. convexhullPolygon\n");
	printf("15. unionPolygon\n");
	printf("16. printPoint\n");
	printf("17. printPolygon\n");
	printf("18. toString\n");

	printf("\nVeuillez choisir la fonction que vous voulez tester ?");
	scanf("%d", &choice);

	switch(choice){
		case 1:
			printf("... Point creation ...\n");
			a = createPoint(0,1);
			printf("Succefull Point creation\n");
			printPoint(a);
			break;

		case 2:
			printf("... Point and Polygon creation ...\n");
			lol=createPolygon();
			lol=addTail(lol, createPoint(0,0));
			lol=addTail(lol, createPoint(1,0));
			lol=addTail(lol, createPoint(0.5,0.5));
			lol=addTail(lol, createPoint(1,1));
			lol=addTail(lol, createPoint(1,2));
			lol=addTail(lol, createPoint(-1,2));
			lol=addTail(lol, createPoint(0,1));
			printf("Succefull Polygon creation\n");
			printPolygon(lol);
			break;
		case 7:
			test = createPoint(-1,0.5);
			lol=createPolygon();
			lol=addTail(lol, createPoint(0,0));
			lol=addTail(lol, createPoint(1,0));
			lol=addTail(lol, createPoint(0.5,0.5));
			lol=addTail(lol, createPoint(1,1));
			lol=addTail(lol, createPoint(1,2));
			lol=addTail(lol, createPoint(-1,2));
			lol=addTail(lol, createPoint(0,1));
			printf("Succefull Polygon called lol\n");
			printPolygon(lol);
			printf("The point is %s in the polygon.\n\n", ((containsPoint(lol, test)))" ":" not ");

		case 8:
			printf("... Point and  2 Polygon creation ...\n");
			
			lol=createPolygon();
			lol=addTail(lol, createPoint(0,0));
			lol=addTail(lol, createPoint(1,0));
			lol=addTail(lol, createPoint(0.5,0.5));
			lol=addTail(lol, createPoint(1,1));
			lol=addTail(lol, createPoint(1,2));
			lol=addTail(lol, createPoint(-1,2));
			lol=addTail(lol, createPoint(0,1));
			
			polyloutre=createPolygon();
			polyloutre=addTail(polyloutre, createPoint(-2,-1));
			polyloutre=addTail(polyloutre, createPoint(-1,3));
			polyloutre=addTail(polyloutre, createPoint(2,3));
			polyloutre=addTail(polyloutre, createPoint(2,-2));

			printf("Succefull Polygon creation\n");

			testing=containsPolygon(lol,polyloutre);

			printf("\nLes deux polygones sont : %d\n", testing);

		case 9:
			printf("... Polygon creation ...\n");
			lol=createPolygon();
			lol=addTail(lol, createPoint(0,0));
			lol=addTail(lol, createPoint(1,0));
			lol=addTail(lol, createPoint(0.5,0.5));
			lol=addTail(lol, createPoint(1,1));
			lol=addTail(lol, createPoint(1,2));
			lol=addTail(lol, createPoint(-1,2));
			lol=addTail(lol, createPoint(10,100));
			printf("Here Polygon before translation\n");
			printPolygon(lol);

			printf("Enter x of first point which define the translation vector\n");
			scanf("%lf", &x1);
			printf("Enter y of first point which define the translation vector\n");
			scanf("%lf", &y1);
			printf("Enter x of second point which define the translation vector\n");
			scanf("%lf", &x2);
			printf("Enter y of second point which define the translation vector\n");
			scanf("%lf", &y2);
			P1 = createPoint(x1,y1);
			P2 = createPoint(x2,y2);

			lol = translatePolygon(lol, P1, P2);
			printf("Now after translation\n");
			printPolygon(lol);
			break;

		case 10:
			printf("\nTesting the rotation with an angle of 2.1rad around the point (1,3)");
			lol=createPolygon();
			lol=addTail(lol, createPoint(0,0));
			lol=addTail(lol, createPoint(1,0));
			lol=addTail(lol, createPoint(0.5,0.5));
			lol=addTail(lol, createPoint(1,1));
			lol=addTail(lol, createPoint(1,2));
			lol=addTail(lol, createPoint(-1,2));
			lol=addTail(lol, createPoint(10,100));
			printf("Here Polygon before rotation\n");
			printPolygon(lol);
			rotatelol = rotatePolygon(lol, createPoint(1,3), 2.1);
			printPolygon(rotatelol);
			break;

		case 11;
			lol=createPolygon();
			lol=addTail(lol, createPoint(0,0));
			lol=addTail(lol, createPoint(1,0));
			lol=addTail(lol, createPoint(0.5,0.5));
			lol=addTail(lol, createPoint(1,1));
			lol=addTail(lol, createPoint(1,2));
			lol=addTail(lol, createPoint(-1,2));
			lol=addTail(lol, createPoint(10,100));
			printf("Here Polygon before scaling\n");
			printPolygon(lol);
			
			printf("\nTesting the scaling by a factor of 3.2\n");
			biglol=scalePolygon(lol,3.2);
			printPolygon(biglol);
			break;

		case 12:
			lol=createPolygon();
			lol=addTail(lol, createPoint(0,0));
			lol=addTail(lol, createPoint(1,0));
			lol=addTail(lol, createPoint(0.5,0.5));
			lol=addTail(lol, createPoint(1,1));
			lol=addTail(lol, createPoint(1,2));
			lol=addTail(lol, createPoint(-1,2));
			lol=addTail(lol, createPoint(10,100));
			printf("Here Polygon before symmetry\n");
			printf("\nTesting the symmetry by the point (0,0)\n");
			symetriclol = centralSymmetry(lol, createPoint(0,0));
			printPolygon(symetriclol);

		case 13:
			printf("... Testing segmentsCross ...");


			printf("Enter x1\n");
			scanf("%lf", &x1);
			printf("Enter y1\n");
			scanf("%lf", &y1);
			printf("Enter x2\n");
			scanf("%lf", &x2);
			printf("Enter y2\n");
			scanf("%lf", &y2);
			printf("Enter x3\n");
			scanf("%lf", &x3);
			printf("Enter y3\n");
			scanf("%lf", &y3);
			printf("Enter x4\n");
			scanf("%lf", &x4);
			printf("Enter y4\n");
			scanf("%lf", &y4);

			testlol = segmentsCross(createPoint(x1,y1), createPoint(x2,y2), createPoint(x3,y3), createPoint(x4,y4));

			if(testlol != NULL){

				printf("\n\nL'intersection est : \n\n	x: %f\n	y: %f\n\n", testlol->value.x, testlol->value.y);

			}
			else{

				printf("\n\nIl n'y a pas d'intersection\n\n");

			}
			break;

		case 14:
			printf("\n ... Test calcul convexhull ...\n");
			lol=createPolygon();
			lol=addTail(lol, createPoint(0,0));
			lol=addTail(lol, createPoint(1,0));
			lol=addTail(lol, createPoint(0.5,0.5));
			lol=addTail(lol, createPoint(1,1));
			lol=addTail(lol, createPoint(1,2));
			lol=addTail(lol, createPoint(-1,2));
			lol=addTail(lol, createPoint(10,100));
			convexpoly = convexhullPolygon(lol);

	        printf("\ntaille : %d\n", convexpoly.size);

	        for(i=0;i<convexpoly.size;i++)
			{
				printf("\n\nx %de point : %f", i+1, convexpoly.head->value.x);
				printf("\ny %de point : %f\n\n", i+1, convexpoly.head->value.y);
				convexpoly.head=convexpoly.head->next;
			}
			printf("Convex hull :\n");
			printPolygon(lol);
			break;
		case 16:
			printf("Enter x1\n");
			scanf("%lf", &x1);
			printf("Enter y1\n");
			scanf("%lf", &y1);
			
			P1 = createPoint(x1,y1);
			
			printPoint(P1);
			break;

		case 17:
			printf("Enter x1\n");
			scanf("%lf", &x1);
			printf("Enter y1\n");
			scanf("%lf", &y1);
			printf("Enter x2\n");
			scanf("%lf", &x2);
			printf("Enter y2\n");
			scanf("%lf", &y2);
			printf("Enter x3\n");
			scanf("%lf", &x3);
			printf("Enter y3\n");
			scanf("%lf", &y3);
			printf("Enter x4\n");
			scanf("%lf", &x4);
			printf("Enter y4\n");
			scanf("%lf", &y4);

			P1 = createPoint(x1,y1);
			P2 = createPoint(x2,y2);
			P3 = createPoint(x3,y3);
			P4 = createPoint(x4,y4);
			lol=createPolygon();
			lol=addTail(lol, P1);
			lol=addTail(lol, P2);
			lol=addTail(lol, P3);
			lol=addTail(lol, P4);
			printPolygon(lol);
			break;

		case 18:
			printf("... Polygon creation ...\n");
			lol=createPolygon();
			lol=addTail(lol, createPoint(0,0));
			lol=addTail(lol, createPoint(1,0));
			lol=addTail(lol, createPoint(0.5,0.5));
			lol=addTail(lol, createPoint(1,1));
			lol=addTail(lol, createPoint(1,2));
			lol=addTail(lol, createPoint(-1,2));
			lol=addTail(lol, createPoint(0,1));
			printf("Succefull Polygon creation\n");
			printf("... String conversion ...\n");
			string = toString(lol);
			printf("Succefull conversion\n");
			printf("%s\n", string);
			break;

	}
	

	return EXIT_SUCCESS;

}

