#include"lse.h"
#include"iostream"
using namespace std;

namespace LSE{

Net::Net(vector<vector<double>> data, double igamma, double iweight) {
	gamma = igamma;
	weight = iweight;
	for(auto vdata: data) {
		if(vdata.size() != 2) {
			cerr << "LSE:: bad raw data\n";
			exit(1);
		}
		vertexList.push_back(Vertex(vdata[0],vdata[1]));
	}
}

double Net::log_sum_exp(){
	int vNum = vertexList.size();
	double sum = 0;
	double psumx = 0;
	double nsumx = 0;
	double psumy = 0;
	double nsumy = 0;
	for (auto vertex: vertexList) {
		psumx += exp(vertex.x/gamma);
		nsumx += exp(-vertex.x/gamma);
		psumy += exp(vertex.y/gamma);
		nsumy += exp(-vertex.y/gamma);
	}

	sum = log(psumx) + log(nsumx) + log(psumy) + log(nsumy);
	sum *= gamma*weight;
	return sum;
}

vector<vector<double>> Net::gradients() {
	int vNum = vertexList.size();
	vector<vector<double>> ans(vNum, vector<double>(2));
	double sum = 0;
	double psumx = 0;
	double nsumx = 0;
	double psumy = 0;
	double nsumy = 0;
	for (auto vertex: vertexList) {
		psumx += exp(vertex.x/gamma);
		nsumx += exp(-vertex.x/gamma);
		psumy += exp(vertex.y/gamma);
		nsumy += exp(-vertex.y/gamma);
	}

	for (int i = 0; i < vNum; i++) {
		ans[i][0] = (exp(vertexList[i].x/gamma)/psumx - exp(-vertexList[i].x/gamma)/nsumx)*weight;
		ans[i][1] = (exp(vertexList[i].y/gamma)/psumx - exp(-vertexList[i].y/gamma)/nsumy)*weight;
	}

	return ans;
}

};
