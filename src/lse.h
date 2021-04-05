#pragma once

#include<iostream>
#include<math.h>
#include<vector>

using namespace std;

namespace LSE{

class Vertex {
public:
	double x;
	double y;
	Vertex(double xp, double yp) {
		x = xp;
		y = yp;
	}

};

class Net {
private:
	vector<Vertex> vertexList;
	double gamma;
	double weight;
public:
	Net(vector<vector<double>> data, double gamma, double weight);
	double log_sum_exp();
	double forWard();
};
};
