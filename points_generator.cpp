/*Реализация интрефейса генератора точек*/
#include "points_generator.h"

point points_generator::Box_Muller() {
	float s, x, y, factor;
	do {
		x = 2 * float(rand()) / RAND_MAX - 1;
		y = 2 * float(rand()) / RAND_MAX - 1;
		s = x * x + y * y;
	} while (s == 0 || s > 1);
	factor = sqrt(-2 * log(s) / s);
	return point( x*factor, y*factor );
}
		
vector<point> points_generator::generate_points(int N) {
	srand(time(0));
	int count = 0;
	vector<point> result;
	for (int i = 0; i < N; i++)
		result.push_back(Box_Muller());
	return result;
}