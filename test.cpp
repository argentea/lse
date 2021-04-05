#include"src/lse.h"
#include "src/parser.h"
int main(int argc, char*  argv[]){
	if(argc != 2) {
		cerr << "bad argument\n";
		return 1;
	}
	Parser::Parser p = Parser::Parser(argv[1]);

	cout << LSE::Net(p.getVertexs(), p.getGamma(), p.getWeight()).log_sum_exp() << endl;
	vector<vector<double>> myans = LSE::Net(p.getVertexs(), p.getGamma(), p.getWeight()).gradients();
	for(int i = 0; i < myans.size(); i++) {
		cout << myans[i][0] << "  " << myans[i][1] << endl;
	}
	return 0;
}
