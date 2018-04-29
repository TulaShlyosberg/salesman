/*��������� ���������� �������������*/
#pragma once
#include "points_generator.h"
#include "salesman_graph.h"
#include "template_graph.h"
#include<cmath>
#include<iostream>

class mst_salesman_experiment {
	vector<double> average_quality;
	vector<double> variation_const;
	vector<pair<int, int>> params;
public:
	mst_salesman_experiment();

	//������ iter_count ������������� �� points_count ������
	void do_experiment(int points_count, int iter_count);

	//������ 20 ������������� ��� ���� ����� � ���������� �� ��������� �� begin_diap
	//�� end_diap ������������
	void do_plural_experiment(int begin_diap, int end_diap);

	//������� ������ ������������
	friend ostream& operator<<(ostream& os, const mst_salesman_experiment& mse);

	//������� ������ ���� ���������� �������������
	void clear_data();
};
