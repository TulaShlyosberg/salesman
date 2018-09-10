/* Интерфейс генератора точек */

using namespace std;
using point = pair<float, float>;


class points_generator {
public:
	//генерирует 1 точку на плоскости с нормальным распределением по обеим ос¤м
	//использу¤ метод Сокса-Мюллера
	pair<float, float> Box_Muller();

	//генерирует N точек
	vector<point> generate_points(int N);
};
