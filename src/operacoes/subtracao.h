#include <string>
#include <iostream>
#include <vector>

using namespace std;

class subtracao{
   public:
      static void gerar(vector<string> *dados, char *inicial, char *final);
};

void subtracao::gerar(vector<string> *dados, char *inicial, char *final){
	*inicial = 'I';
	*final = 'F';
	
	//EXEMPLO 1
    dados->push_back("I,I=0,I,D");
    dados->push_back("0,*=0,*,D");
   	dados->push_back("0,_=1,_,D");
    dados->push_back("1,_=2,_,E");
    dados->push_back("1,*=1,*,D");
    dados->push_back("1,A=1,A,E");
    dados->push_back("2,*=3,A,E");
    dados->push_back("2,_=5,_,D");
    dados->push_back("2,A=2,A,E");
    dados->push_back("3,*=3,*,E");
    dados->push_back("3,_=3,_,E");
    dados->push_back("3,I=4,I,D");
    dados->push_back("4,*=0,_,D");
    dados->push_back("4,_=4,_,D");
    dados->push_back("4,A=8,A,D");
    dados->push_back("5,_=6,_,D");
    dados->push_back("5,A=5,*,D");
    dados->push_back("6,*=6,*,D");
    dados->push_back("6,_=7,*,E");
    dados->push_back("7,*=7,*,E");
    dados->push_back("7,_=2,_,E");
    dados->push_back("8,*=F,_,D");
    dados->push_back("8,_=8,_,D");
    dados->push_back("8,A=9,_,D");
    dados->push_back("9,_=10,_,D");
    dados->push_back("9,A=9,A,D");
    dados->push_back("10,*=10,*,D");
    dados->push_back("10,_=11,_,D");
    dados->push_back("11,*=11,*,D");
    dados->push_back("11,_=12,*,E");
    dados->push_back("12,*=12,*,E");
    dados->push_back("12,_=12,_,E");
    dados->push_back("12,A=12,A,E");
    dados->push_back("12,I=8,I,D");
	
	/* EXEMPLO 2
	dados->push_back("I,I=0,I,D");
    dados->push_back("0,*=0,*,D");
    dados->push_back("0,_=1,_,D");
    dados->push_back("1,*=1,*,D");
    dados->push_back("1,_=2,_,E");
    dados->push_back("2,*=3,_,E");
    dados->push_back("2,_=F,_,D");
    dados->push_back("3,*=3,*,E");
    dados->push_back("3,_=3,_,E");
    dados->push_back("4,*=0,_,D");
    dados->push_back("4,_=4,_,D");
    dados->push_back("3,I=4,I,D");
    */   
}
