#include <string>
#include <iostream>
#include <vector>

using namespace std;

class multiplicacao{
   public:
      static void gerar(vector<string> *dados, string *inicial, string *final);
};

void multiplicacao::gerar(vector<string> *dados, string *inicial, string *final){
	*inicial = '>';
	*final = 'F';
    dados->push_back(">,>=0,>,D");
    dados->push_back("0,*=1,A,D");
    dados->push_back("0,_=10,_,D");
    dados->push_back("1,*=1,*,D");
    dados->push_back("1,_=2,_,D");
    dados->push_back("2,*=2,*,D");
    dados->push_back("2,_=3,_,E");
    dados->push_back("2,Y=2,Y,D");
    dados->push_back("3,*=4,Y,D");
    dados->push_back("4,_=5,_,D");
    dados->push_back("4,Y=4,Y,D");
    dados->push_back("5,*=5,*,D");
    dados->push_back("5,_=6,*,E");
    dados->push_back("6,*=6,*,E");
    dados->push_back("6,_=7,_,E");
    dados->push_back("7,*=4,Y,D");
    dados->push_back("7,_=8,_,D");
    dados->push_back("7,Y=7,Y,E");
    dados->push_back("8,_=9,_,E");
    dados->push_back("8,Y=8,*,D");
    dados->push_back("9,*=9,*,E");
    dados->push_back("9,_=9,_,E");
    dados->push_back("9,A=0,A,D");
    dados->push_back("A,*=10,*,D");
    dados->push_back("10,_=11,_,E");
    dados->push_back("10,*=10,*,D");
    dados->push_back("11,*=11,_,E");
    dados->push_back("11,_=11,_,E");
    dados->push_back("11,A=11,_,E");
    dados->push_back("11,_=F,_,D");    
    
}
