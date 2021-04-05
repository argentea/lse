#pragma once
#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>

#define PARSERTEST 1
#define CHECKANS 0

using namespace std;
namespace Parser {
class Parser {
private:
	vector<vector<double>> vertexList;
#if CHECKANS
	vector<vector<double>> gradientsList;
	double ans;
#endif
	double gamma;
	double weight;
public:
	Parser(const char* fileName);
	vector<vector<double>>& getVertexs() {return vertexList;};
	double getGamma() {return gamma;};
	double getWeight() {return weight;};

};
};
