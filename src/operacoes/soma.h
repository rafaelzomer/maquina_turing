#include <string>
#include <iostream>
#include <vector>

using namespace std;

class soma{
   public:
      static void gerar(vector<string> *dados, string *inicial, string *final);
};

void soma::gerar(vector<string> *dados, string *inicial, string *final){
	*inicial = 'I';
	*final = 'F';
	dados->push_back("I,I=0,I,D");
	dados->push_back("0,*=0,*,D");
	dados->push_back("0,_=1,*,D");
	dados->push_back("1,*=1,*,D");
	dados->push_back("1,_=2,_,E");
	dados->push_back("2,*=2,_,D");
	dados->push_back("2,_=F,_,D");
}
