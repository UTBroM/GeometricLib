#include <polygon.h>


int main(int argc, char* argv[]) {

	Polygon lol;
	Point test = createPoint(-1,0.5);
	int i;
	double x1=0, x2=0, x3=0, x4=0, y1=0, y2=0, y3=0, y4=0;
	Intersection* testlol;

	lol=createPolygon();
	lol=addPoint(lol, createPoint(0,0));
	lol=addPoint(lol, createPoint(1,0));
	lol=addPoint(lol, createPoint(0.5,0.5));
	lol=addPoint(lol, createPoint(1,1));
	lol=addPoint(lol, createPoint(1,2));
	lol=addPoint(lol, createPoint(-1,2));
	lol=addPoint(lol, createPoint(0,1));

	printf("\n\ntaille : %d", lol.size);

	for(i=0;i<lol.size;i++)
	{

		printf("\n\nx %de point : %f", i+1, lol.head->value.x);
		printf("\ny %de point : %f\n\n", i+1, lol.head->value.y);
		lol.head=lol.head->next;

	}

	printf("\nTest point coordinates :\n\n	x:%f\n	y:%f\n\n", test.x,test.y);

	printf("The point is%sin the polygon.\n\n", ((containsPoint(lol, test)))?" ":" not ");

	printf("\nSuppression du 2e élément...\n");
	lol=removePoint(lol, 2);

        printf("\n\ntaille : %d", lol.size);

        for(i=0;i<lol.size;i++)
	{

		printf("\n\nx %de point : %f", i+1, lol.head->value.x);
		printf("\ny %de point : %f\n\n", i+1, lol.head->value.y);
		lol.head=lol.head->next;

	}


	printf("\n==================================\n\nTest d'une intersection");

	printf("\n\nEntrez les coordonées du point 1 :\n	x:");
	scanf("%lf",&x1);
	printf("\n	y:");
	scanf("%lf",&y1);
	printf("\n\nEntrez les coordonées du point 2 :\n	x:");
	scanf("%lf",&x2);
	printf("\n	y:");
	scanf("%lf",&y2);
	printf("\n\nEntrez les coordonées du point 3 :\n	x:");
	scanf("%lf",&x3);
	printf("\n	y:");
	scanf("%lf",&y3);
	printf("\n\nEntrez les coordonées du point 4 :\n	x:");
	scanf("%lf",&x4);
	printf("\n	y:");
	scanf("%lf",&y4);

	testlol = segmentsCross(createPoint(x1,y1), createPoint(x2,y2), createPoint(x3,y3), createPoint(x4,y4));

	if(testlol != NULL){

		printf("\n\nL'intersection est : \n\n	x: %f\n	y: %f\n\n", testlol->value.x, testlol->value.y);

	}
	else{

		printf("\n\nIl n'y a pas d'intersection\n\n");

	}

	free(testlol);

	return EXIT_SUCCESS;

}

