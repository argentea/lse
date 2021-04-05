#include"parser.h"
#include<errno.h>
#include<cstring>
#define PARSERTEST 0
using namespace std;

namespace Parser {
Parser::Parser(const char* fileName) {
	int pinNum = 0;

	string line;
	stringstream sline;
	ifstream dataFile (fileName);
	if(dataFile.is_open()) {
		getline(dataFile, line);
		sline << line;
		string tmp;
		bool getPinNum = false;
		bool getWeight = false;
		while(!sline.eof()) {
			sline >> tmp;
			if(!getPinNum&&stringstream(tmp) >> pinNum) {
				getPinNum = true;
				if(PARSERTEST) {
					cout << endl << "Parser::pinNum: " << pinNum << endl;
				}
				getline(dataFile, line);
				sline.clear();
				sline << line;
				continue;
			}
			if(getPinNum&&!getWeight&&stringstream(tmp) >> weight) {
				getWeight = true;
				if(PARSERTEST) {
					cout << endl << "Parser::weight: " << weight << endl;
				}
				getline(dataFile, line);
				sline.clear();
				sline << line;
				continue;
			}
			if(getPinNum&&getWeight&&stringstream(tmp) >> gamma) {
				if(PARSERTEST) {
					cout << endl << "Parser::gamma: " << gamma << endl;
				}
				break;
			}

		}
		vertexList.assign(pinNum, vector<double>(2));
		int indexi = 0;
		int tmpint = 0;
		while (getline(dataFile, line)) {
			if(PARSERTEST) {
				cout << line << endl;
			}
			stringstream dline;
			dline << line;
			string tmp;
			int indexj = 0;
			while (!dline.eof()){
				dline >> tmp;
				if(stringstream(tmp) >> vertexList[indexi][indexj]){
					if(PARSERTEST) {
						cout << vertexList[indexi][indexj] << " ";
					}
					indexj++;
					if(indexj >= 2){
						indexi++;
						indexj = 0;
					}

				}
			}
			if(indexi == pinNum){
				break;
			}
		}
		dataFile.close();
	}
	else {
		cerr << "Can not open the file\n";
		cerr << strerror(errno) << endl;
		exit(1);
	}
}
};
