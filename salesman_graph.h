/*Header - ��������� ������ � ����������� ����� ��� ������ ������������. 
������������ ����� ����� �����. ����� �� ������, �.�.
���� ������, � ������ ����� �������� ����*/
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
	//����������� �� ������ �����
	salesman_graph(const vector<point>& in_points);

	//��������� ������������ ��������� ������ (������������ �������� �����)
	template_graph<point> salesman_mst() const;

	//��������� ���������� ����� ����� �������
	float get_distance(const point& point_1, const point& point_2) const;

	//������� ���� ������������� ������ � ����� (������������ ���� ���������� dfs ���
	//��������� ���� �����, ������� �� ������� 0)
	float get_gamilton_cycle_weight() const;
};