#include <string>
#include <iostream>
#include <vector>

using namespace std;

class multiplicacao{
   public:
      static void gerar(vector<string> *dados, char *inicial, char *final);
};

void multiplicacao::gerar(vector<string> *dados, char *inicial, char *final){
	*inicial = 'I';
	*final = 'F';
	//fixme
    dados->push_back("I,I=0,I,D");
    dados->push_back("0,*=1,A,D");
    dados->push_back("1,*=1,*,D");
    dados->push_back("1,_=2,_,D");
    dados->push_back("1,A=1,A,E");
    dados->push_back("1,I=8,->,D");
    dados->push_back("2,*=3,B,D");
    dados->push_back("2,_=3,_,D");
    dados->push_back("3,*=3,*,D");
    dados->push_back("3,_=4,_,D");
    dados->push_back("4,*=4,*,D");
    dados->push_back("4,_=5,*,D");
    dados->push_back("5,*=5,*,E");
    dados->push_back("5,_=5,_,E");
    dados->push_back("5,B=8,B,D");
    dados->push_back("6,*=3,B,D");
    dados->push_back("6,_=7,_,E");
    dados->push_back("7,_=1,_,E");
    dados->push_back("7,B=7,*,E");
    dados->push_back("8,*=F,*,D");
    dados->push_back("8,_=8,_,D");
    dados->push_back("8,B=8,_,D");
    dados->push_back("8,A=8,_,D");
}
