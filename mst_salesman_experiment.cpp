#include "mst_salesman_experiment.h"

mst_salesman_experiment::mst_salesman_experiment(){}
void mst_salesman_experiment::do_experiment(int points_count, int iter_count) {
	vector<double> data(iter_count);
	params.push_back({ points_count, iter_count});
	double sum = 0;
	for (int i = 0; i < iter_count; i++) {
		points_generator pg;
		vector<point> points = pg.generate_points(points_count);
		salesman_graph sg{ points };
		template_graph<point> tg = sg.salesman_mst();
		data[i] =  tg.weight() / sg.get_gamilton_cycle_weight();
		sum += data[i];
	}
	average_quality.push_back(sum / iter_count);
	if (iter_count == 1) {
		variation_const.push_back(-1);
		return;
	}
	float sum_sqr = 0;
	for (auto i : data) sum_sqr += (i - average_quality[average_quality.size() - 1]) *
		(i - average_quality[average_quality.size() - 1]);
	variation_const.push_back(sqrt(sum_sqr / (iter_count - 1)));
}

ostream& operator<<(ostream& os, const mst_salesman_experiment& mse) {
	for (int i = 0; i < mse.average_quality.size(); i++) {
		os << "N: " << mse.params[i].first << " iter_count: " << mse.params[i].second <<
			" average quality: " << mse.average_quality[i]
			<< "   constant of variation: " << mse.variation_const[i] << endl;
	}
	return os;
}

void mst_salesman_experiment::do_plural_experiment(int begin_diap, int end_diap) {
	for (int i = begin_diap; i <= end_diap; i++)
		do_experiment(i, 20);
}

void mst_salesman_experiment::clear_data() {
	average_quality.clear();
	variation_const.clear();
	params.clear();
}