#include <polygon.h>


int main(int argc, char* argv[]) {

	Polygon lol;
	Point test = createPoint(-1,0.5);
	int i;

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






	return EXIT_SUCCESS;

}

