/*Интерфейс класса с реализацией графа для задачи коммивояжера. 
Представляет собой набор точек. Ребра не храним, т.к.
граф полный, и всякое ребро заведомо есть*/
#include "template_graph.h"
using namespace std;
using point = pair<float, float>;

class salesman_graph {
	int _size;
	vector<point> points;
public:
	//конструктор по набору точек
	salesman_graph(const vector<point>& in_points);

	//получение минимального остовного дерева (используется алгоритм Прима)
	template_graph<point> salesman_mst() const;

	//получение расстояния между двумя точками
	float get_distance(const point& point_1, const point& point_2) const;

	//перебор всех гамильтоновых циклов в графе (используется чуть измененный dfs для
	//просмотра всех путей, ведущих из вершины 0)
	float get_gamilton_cycle_weight() const;
};
