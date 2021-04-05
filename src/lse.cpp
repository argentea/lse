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

};
