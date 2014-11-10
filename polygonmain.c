#include <polygon.h>


int main(int argc, char* argv[]) {

	Polygon lol;

	lol=createPolygon();
	lol=addPoint(lol, createPoint(12.6,-5.3));
	lol=addPoint(lol, createPoint(-4.1,456.123));

	printf("\n\nx premier point : %f", lol->value.x);
	printf("\ny premier point : %f\n\n", lol->value.y);

	printf("\n\nx 2eme point : %f", lol->next->value.x);
	printf("\ny 2eme point : %f\n\n", lol->next->value.y);

	printf("\n\nx 3eme point : %f", lol->next->next->value.x);
	printf("\ny 3eme point : %f\n\n", lol->next->next->value.y);

	return EXIT_SUCCESS;

}

