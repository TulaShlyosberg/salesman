#include "mst_salesman_experiment.h"
using namespace std;

int main() {
	mst_salesman_experiment mse;
	//�������� ��� ������������ �� 8 ��������
	mse.do_experiment(8, 2);
	//�������� 20 ������������� �� �� 2 �� 8 ������
	mse.do_plural_experiment(2, 8);
	cout << mse;
	system("pause");
}