#include"src/lse.h"
int main(){
	vector<vector<double>> data({{3.261187E+00, 6.771580E-01}, {3.557422E+00, 9.191569E-01}, {4.795245E+00, 4.150934E+00}});
	double gamma = 0.5;
	double weight = 0.183097; 
	double ans = 1.015396E+00;
	cout << abs(LSE::Net(data, gamma, weight).log_sum_exp()-ans) << endl;
	return 0;
}
