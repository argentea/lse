#pragma once
#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>

using namespace std;
namespace Parser {
class Parser {
private:
	vector<vector<double>> vertexList;
	double gamma;
	double weight;
public:
	Parser(const char* fileName);
	vector<vector<double>>& getVertexs() {return vertexList;};
	double getGamma() {return gamma;};
	double getWeight() {return weight;};

};
};
