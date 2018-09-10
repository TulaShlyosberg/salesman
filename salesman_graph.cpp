/*Реализация класса графа из задачи коммивояжера*/
#pragma once
#include<vector>
#include<set>
#include<algorithm>
#include<cmath>
#include<stack>
#include "salesman_graph.h"

salesman_graph::salesman_graph(const vector<point>& in_points) {
	points = in_points;
	_size = in_points.size();
}

float salesman_graph::get_distance(const point& point_1, const point& point_2) const {
	float delta_x = point_1.first - point_2.first;
	float delta_y = point_1.second - point_2.second;
	return sqrt(delta_x * delta_x + delta_y * delta_y);
}

template_graph<point> salesman_graph::salesman_mst() const {
	template_graph<point> result{ points };
	set<int> not_used;
	for (int i = 1; i < _size; i++) not_used.emplace(i);
	vector<pair<int, int>> out_edges;
	float begin_ver = 0;
	auto comp = [this](const pair<int, int>& ind_point_1, const pair<int, int>& int_point_2) {
		float term_1 = get_distance(points[ind_point_1.first], points[ind_point_1.second]);
		float term_2 = get_distance(points[int_point_2.first], points[int_point_2.second]);
		return term_1 > term_2;
	};
	for (auto i : not_used) {
		out_edges.push_back({ 0 , i });
		push_heap(out_edges.begin(), out_edges.end(), comp);
	}
	while (not_used.size() > 0) {
		pair<int, int> edge;
		do {
			edge = out_edges[0];
			pop_heap(out_edges.begin(), out_edges.end(), comp);
			out_edges.pop_back();
		} while (not_used.find(edge.second) == not_used.end());
		not_used.erase(edge.second);
		result.set_edge(points[edge.first], points[edge.second],
			get_distance(points[edge.first], points[edge.second]));
		result.set_edge(points[edge.second], points[edge.first],
			get_distance(points[edge.first], points[edge.second]));
		for (auto i : not_used) {
			out_edges.push_back({ edge.second, i });
			push_heap(out_edges.begin(), out_edges.end(), comp);
		}
	}
	return result;
}

float salesman_graph::get_gamilton_cycle_weight() const {
	if (_size == 2) return 2 * get_distance(points[0], points[1]);
	int count = 0;
	stack<int> dfs_stack;
	dfs_stack.push(0);
	float length = 0;
	vector<bool> visited;
	visited.assign(_size, true);
	vector<vector<bool>> cur_visited(_size);
	cur_visited[0].resize(_size);
	vector<int> parents(_size);
	for (int i = 1; i < _size; i++) {
		parents[i] = i - 1;
		cur_visited[i].resize(_size);
		cur_visited[i - 1][i] = true;
		dfs_stack.push(i);
	}
	int visited_count = _size;
	float min = INFINITY;
	while (!dfs_stack.empty()) {
		int v = dfs_stack.top();
		visited[v] = true;
		bool flag = false;
		for (int i = 0; i < _size; i++)
			if (!visited[i] && !cur_visited[v][i]) {
				flag = true;
				parents[i] = v;
				dfs_stack.push(i);
				cur_visited[v][i] = true;
				break;
			}

		if (!flag) {
			dfs_stack.pop();
			visited[v] = false;
			for (int i = 0; i < _size; i++) cur_visited[v][i] = false;
			if (visited_count == _size) {
				float cur_weight = get_distance(points[v], points[0]);
				int temp = v;
				while (temp != parents[temp]) {
					cur_weight += get_distance(points[parents[temp]], points[temp]);
					temp = parents[temp];
				}
				if (min > cur_weight) min = cur_weight;
			}
			visited_count--;
		}
		else visited_count++;
	}
	return min;
}
