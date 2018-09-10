/*Интерфейс генератора экспериментов*/
#pragma once
#include<vector>
#include<iostream>
using namespace std;

class mst_salesman_experiment {
	vector<double> average_quality;   //среднее качества приближения
	vector<double> variation_const;   //среднекрвадратичное отклонение
	vector<pair<int, int>> params;
public:
	mst_salesman_experiment();

	//Делает iter_count экспериментов на points_count точках
	void do_experiment(int points_count, int iter_count);

	//Делает 20 экспериментов для всех точек в количестве из диапазона от begin_diap
	//До end_diap включительно
	void do_plural_experiment(int begin_diap, int end_diap);

	//Выводит данные эксперимента
	friend ostream& operator<<(ostream& os, const mst_salesman_experiment& mse);

	//Очищает данные всех предыдущих экспериментов
	void clear_data();
};
