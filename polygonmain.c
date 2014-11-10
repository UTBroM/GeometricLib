#include <polygon.h>


int main(int argc, char* argv[]) {

	Polygon lol;
	lol=createPolygon();
	printf("\n\nx premier point : %f", lol->value.x);
	printf("\ny premier point : %f\n\n", lol->value.y);
	return EXIT_SUCCESS;

}

