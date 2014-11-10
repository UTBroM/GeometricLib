#include <polygon.h>


int main(int argc, char* argv[]) {

	Polygon lol;
	Point test;

	lol=createPolygon();
	printf("\n\nx premier point : %f", lol->value.x);
	printf("\ny premier point : %f\n\n", lol->value.y);

	test.x=12.5;
	test.y=-3.6;

	lol=addPoint(lol, test);

	printf("\n\nx 2eme point : %f", lol->next->value.x);
	printf("\ny 2eme point : %f\n\n", lol->next->value.y);

	printf("\n\nx 3eme point : %f", lol->next->next->value.x);
	printf("\ny 3eme point : %f\n\n", lol->next->next->value.y);

	return EXIT_SUCCESS;

}

