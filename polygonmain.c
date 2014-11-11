#include <polygon.h>


int main(int argc, char* argv[]) {

	Polygon lol;

	lol=createPolygon();
	lol=addPoint(lol, createPoint(12.6,-5.3));
	lol=addPoint(lol, createPoint(-4.1,456.123));
	lol=addPoint(lol, createPoint(23.7,1));

	printf("\n\ntaille : %d", lol.size);

	for(i=0;i<lol.size;i++)
	{

		printf("\n\nx %de point : %f", i, lol.head->value.x);
		printf("\ny %de point : %f\n\n", i, lol.head->value.y);
		lol.head=lol.head->next;

	}

	printf("\n\nx 2eme point : %f", lol.head->next->value.x);
	printf("\ny 2eme point : %f\n\n", lol.head->next->value.y);

	printf("\n\nx 3eme point : %f", lol.head->next->next->value.x);
	printf("\ny 3eme point : %f\n\n", lol.head->next->next->value.y);

	printf("\nSuppression du 2e élément...\n");
	lol=removePoint(lol, 2);

        printf("\n\ntaille : %d", lol.size);

        for(i=0;i<lol.size;i++)
	{

		printf("\n\nx %de point : %f", i, lol.head->value.x);
		printf("\ny %de point : %f\n\n", i, lol.head->value.y);
		lol.head=lol.head->next;

	}






	return EXIT_SUCCESS;

}

