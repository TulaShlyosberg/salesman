/* Интерфейс генератора точек */
#pragma once
#include<vector>
#include<ctime>
#include<cmath>
using namespace std;
using point = pair<float, float>;


class points_generator {
public:
	//генерирует 1 точку на плоскости с нормальным распределением по обеим осям
	//используя метод Бокса-Мюллера
	pair<float, float> Box_Muller();

	//генерирует N точек
	vector<point> generate_points(int N);
};
