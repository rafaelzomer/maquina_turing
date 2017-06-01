#include <string>
#include <iostream>
#include "estado.h"
#include <map>
#include <vector>

using namespace std;

class maquina{
   private:
      int codigo, i = 0;
      string fita;
      string nome;
      char inicial, final;
      map<char, map<char, estado> > linhas;
      void init(char est, char simbolo);
   
   public:
      maquina(vector<string> *dados, char inicial, char final);
      void ler(string fita);
};

maquina::maquina(vector<string> *dados, char inicial, char final) {
	this->inicial = inicial;
	this->final = final;
	estado es;
	char lin, col; 
  	for(int i = 0; i < dados->size(); i++) {
	  	string dado = dados->at(i);
	  	lin = dado[0];
		col = dado[2];
		es.proximoEstado = dado[4];
		es.escreve = dado[6];
		es.direcaoMovimento = dado[8];
		this->linhas[lin][col] = es;	
	}
}

void maquina::ler(string fita){
	this->fita = fita;
	this->init(this->inicial, this->inicial);
}

void maquina::init(char est, char simbolo) {
	estado es = this->linhas[est][simbolo];
	
	if (es.proximoEstado == ' ')
	{
		cout << "Erro: estado nao encontrado";
		return;
	}
	
	cout << "est= " << est << "/" << simbolo << endl;
	cout << "dir: " << es.proximoEstado << ',' << es.escreve << ',' << es.direcaoMovimento << endl;
	
	char proxSim;
	
	int anterior = this->i;
	if(es.direcaoMovimento == 'D') {
		proxSim = this->fita[++this->i];
	} else {
		proxSim = this->fita[--this->i];	
	}
	
	this->fita[anterior] = es.escreve;
	
	
	cout << "FITA: " << this->fita << endl;
	
	cout << "init: " << " = " << es.proximoEstado << '/' << proxSim << endl;
	if (this->fita.empty() || es.proximoEstado == 'F')
	{
		cout << "Sucesso: fita lida com sucesso!" << endl;
		return;
	}
	
	this->init(es.proximoEstado, proxSim);	
}
