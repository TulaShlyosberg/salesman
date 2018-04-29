/*Header - интерфейс класса с реализацией графа дл€ задачи коммиво€жера. 
ѕредставл€ет собой набор точек. –ебра не храним, т.к.
граф полный, и вс€кое ребро заведомо есть*/
#pragma once
#include<vector>
#include<set>
#include<algorithm>
#include<cmath>
#include<stack>
#include "template_graph.h"
using namespace std;
using point = pair<float, float>;

class salesman_graph {
	int _size;
	vector<point> points;
public:
	//конструктор по набору точек
	salesman_graph(const vector<point>& in_points);

	//получение минимального остовного дерева (используетс€ алгоритм ѕрима)
	template_graph<point> salesman_mst() const;

	//получение рассто€ни€ между двум€ точками
	float get_distance(const point& point_1, const point& point_2) const;

	//перебор всех гамильтоновых циклов в графе (используетс€ чуть измененный dfs дл€
	//просмотра всех путей, ведущих из вершины 0)
	float get_gamilton_cycle_weight() const;
};