/*Шаблонный класс ориенторированного графа, где вершинами являются элементы произвольного типа,
у кторых есть оператор < (для использования map)*/
#pragma once
#include<vector>
#include<map>
using namespace std;

template<class vertex_type>
class template_graph {
	//словарь, сопоставляющий вершине ее номер
	map<vertex_type, int> vertices_hash;

	//вектор, связывающий номер вершины и ее саму
	vector<vertex_type> vertices_number;

	//списки смежности с вещественными весами
	vector<vector<pair<int, float>>> edges;
public:

	//конструткор по списку вершин
	template_graph(const vector<vertex_type>& vertices) {
		vertices_number = vertices;
		for (int i = 0; i < vertices.size(); i++)
			vertices_hash.insert({ vertices[i], i });
		edges.resize(vertices.size());
	}

	//процедура, создающая ребро из from в to весом cost
	void set_edge(vertex_type from, vertex_type to, float cost) {
		edges[vertices_hash[from]].push_back({ vertices_hash[to], cost });
	}

	//возвращает массив потомков данной вершины
	vector<pair<vertex_type, float>> adjacent(vertex_type parent) {
		hash = vertices_hash[parent];
		vector<vertex_type> result(edges[hash].size());
		for (int i = 0; i < edges[hash].size(); i++) {
			result[i].first = vertices_number[edges[hash][i]];
			result[i].second = edges[hash][i].second;
		}
		return result;
	}

	//возвращает количество вершин
	int size() const {
		return vertices_number.size();
	}

	//возвращает суммарный вес ребер графа
	double weight() const {
		double result = 0;
		for (auto out_edges : edges)
			for (auto edge : out_edges)
				result += edge.second;
		return result;
	}

	//конструктор копирования
	template_graph(const template_graph& c_tg) {
		edges = c_tg.edges;
		vertices_hash = c_tg.vertices_hash;
		vertices_number = c_tg.vertices_number;
	}

	//оператор присваивания
	template_graph& operator==(const template_graph& c_tg) {
		edges = c_tg.edges;
		vertices_hash = c_tg.vertices_hash;
		vertices_number = c_tg.vertices_number;
		return *this;
	}
};
