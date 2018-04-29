/* ��������� ���������� ����� */
#pragma once
#include<vector>
#include<ctime>
#include<cmath>
using namespace std;
using point = pair<float, float>;


class points_generator {
public:
	//���������� 1 ����� �� ��������� � ���������� �������������� �� ����� ����
	//��������� ����� �����-�������
	pair<float, float> Box_Muller();

	//���������� N �����
	vector<point> generate_points(int N);
};
