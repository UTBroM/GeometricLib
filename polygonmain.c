#include <polygon.h>


int main(int argc, char* argv[]) {

	Polygon lol, polyloutre, convexpoly, biglol, symetriclol, rotatelol;
	Point test = createPoint(-1,0.5);
	Point P1, P2;
	int i;
	double x1=0, x2=0, x3=0, x4=0, y1=0, y2=0, y3=0, y4=0;
	char* string;
	Intersection* testlol;
	Status testing;

	lol=createPolygon();
	lol=addTail(lol, createPoint(0,0));
	lol=addTail(lol, createPoint(1,0));
	lol=addTail(lol, createPoint(0.5,0.5));
	lol=addTail(lol, createPoint(1,1));
	lol=addTail(lol, createPoint(1,2));
	lol=addTail(lol, createPoint(-1,2));
	lol=addTail(lol, createPoint(0,1));

	printf("Testing printPolygon\n");
	printPolygon(lol);

	printf("Testing translatePolygon\n");
	P1 = createPoint(0,0);
	P2 = createPoint(1,1);
	lol = translatePolygon(lol, P1, P2);
	printPolygon(lol);

	printf("Testing toString\n");
	string = toString(lol);
	printf("%s\n", string);

	polyloutre=createPolygon();
	polyloutre=addTail(polyloutre, createPoint(-2,-1));
	polyloutre=addTail(polyloutre, createPoint(-1,3));
	polyloutre=addTail(polyloutre, createPoint(2,3));
	polyloutre=addTail(polyloutre, createPoint(2,-2));

	printf("\n\ntaille : %d", lol.size);

	for(i=0;i<lol.size;i++)
	{

		printf("\n\nx %de point : %f", i+1, lol.head->value.x);
		printf("\ny %de point : %f\n\n", i+1, lol.head->value.y);
		lol.head=lol.head->next;

	}

	printf("\nTest point coordinates :\n\n	x:%f\n	y:%f\n\n", test.x,test.y);

	printf("The point is%sin the polygon.\n\n", ((containsPoint(lol, test)))?" ":" not ");

	/*printf("\nSuppression du 2e élément...\n");
	lol=removePoint(lol, 2);*/

        printf("\n\ntaille : %d", lol.size);

        for(i=0;i<lol.size;i++)
	{

		printf("\n\nx %de point : %f", i+1, lol.head->value.x);
		printf("\ny %de point : %f\n\n", i+1, lol.head->value.y);
		lol.head=lol.head->next;

	}

	testing=containsPolygon(lol,polyloutre);

	printf("\n\nLes deux polygones sont : %d", testing);

	printf("\n==================================\n\nTest d'une intersection");

	printf("\n\nEntrez les coordonées du point 1 :\n	x:");
	x1=-1;
	printf("%f",x1);
	printf("\n	y:");
	y1=0.25;
	printf("%f",y1);
	printf("\n\nEntrez les coordonées du point 2 :\n	x:");
	x2=2.1;
	printf("%f",x2);
	printf("\n	y:");
	y2=-1.4;
	printf("%f",y2);
	printf("\n\nEntrez les coordonées du point 3 :\n	x:");
	x3=-1.4;
	printf("%f",x3);
	printf("\n	y:");
	y3=-0.45;
	printf("%f",y3);
	printf("\n\nEntrez les coordonées du point 4 :\n	x:");
	x4=12;
	printf("%f",x4);
	printf("\n	y:");
	y4=11.45;
	printf("%f",y4);

	testlol = segmentsCross(createPoint(x1,y1), createPoint(x2,y2), createPoint(x3,y3), createPoint(x4,y4));

	if(testlol != NULL){

		printf("\n\nL'intersection est : \n\n	x: %f\n	y: %f\n\n", testlol->value.x, testlol->value.y);

	}
	else{

		printf("\n\nIl n'y a pas d'intersection\n\n");

	}

	printf("\n\n test du calcul d'un convexhull :\n");

	convexpoly = convexhullPolygon(lol);

        printf("\ntaille : %d\n", convexpoly.size);

        for(i=0;i<convexpoly.size;i++)
	{

		printf("\n\nx %de point : %f", i+1, convexpoly.head->value.x);
		printf("\ny %de point : %f\n\n", i+1, convexpoly.head->value.y);
		convexpoly.head=convexpoly.head->next;

	}

	printPolygon(lol);

	printf("\nTesting the scaling by a factor of 3.2\n");
	biglol=scalePolygon(lol,3.2);
	printPolygon(biglol);

	printf("\nTesting the symmetry by the point (0,0)\n");
	symetriclol = centralSymmetry(lol, createPoint(0,0));
	printPolygon(symetriclol);

	printf("\nTesting the rotation with an angle of 2.1rad around the point (2,4)");
	rotatelol = rotatePolygon(lol, createPoint(0,0), 2.1);
	printPolygon(rotatelol);

	free(testlol);

	return EXIT_SUCCESS;

}

