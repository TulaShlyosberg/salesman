#include "mst_salesman_experiment.h"
using namespace std;

int main() {
	mst_salesman_experiment mse;
	//Проводим два эксперимента на 8 вершинах
	mse.do_experiment(8, 2);
	//проводим 20 экспериментов на от 2 до 8 вершин
	mse.do_plural_experiment(2, 8);
	cout << mse;
	system("pause");
}