#include <string>
#include <iostream>
#include <vector>

using namespace std;

class subtracao{
   public:
      static void gerar(vector<string> *dados, string *inicial, string *final);
};

void subtracao::gerar(vector<string> *dados, string *inicial, string *final){
	*inicial = ">";
	*final = "F";
	
	dados->push_back(">,>=0,>,D");
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
    dados->push_back("3,>=4,>,D");   
}
