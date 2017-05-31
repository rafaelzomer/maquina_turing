#include <string>
#include <iostream>
#include "estado.h"
#include <map>
#include <vector>

using namespace std;

class maquina{
   private:
      int codigo;
      string nome;
      map<char, map<char, estado> > linhas;
      void init();
   
   public:
      maquina();
      void ler(vector<string> *dados);
};

maquina::maquina(){}

void maquina::ler(vector<string> *dados){
	estado es;
	char lin, col; 
  	for(int i = 0; i < dados->size(); i++) {
	  	string dado = dados->at(i);
	  	cout << "dado= "<< dado << endl;
	  	lin = dado[0];
		col = dado[2];
		es.proximoEstado = dado[4];
		es.escreve = dado[6];
		es.direcaoMovimento = dado[8];
		this->linhas[lin][col] = es;	
	}
}

void init() {
	
}
