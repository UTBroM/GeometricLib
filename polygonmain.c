#include <polygon.h>


int main(int argc, char* argv[]) {

	Polygon lol, polyloutre;
	Point test = createPoint(-1,0.5);
	int i;
	double x1=0, x2=0, x3=0, x4=0, y1=0, y2=0, y3=0, y4=0;
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

	printf("\nSuppression du 2e élément...\n");
	lol=removePoint(lol, 2);

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

	free(testlol);

	return EXIT_SUCCESS;

}

