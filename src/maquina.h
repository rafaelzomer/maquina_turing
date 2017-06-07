#include <string>
#include <algorithm>
#include <iostream>
#include "estado.h"
#include <map>
#include <vector>
#include "uteis/sleep.h"

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
	fita = fita+"_____________";
	//Acrescenta simbolo inicial caso nao houver
	if (this->fita[0] != this->inicial)
	{
		fita = this->inicial + fita;
	}
	//Substitui os espacos por underline
	replace( fita.begin(), fita.end(), ' ', '_');
	this->fita = fita;
	this->init(this->inicial, this->inicial);
}

void maquina::init(char est, char simbolo) {
	clear_screen();
	estado es = this->linhas[est][simbolo];
	
	if (es.proximoEstado == ' ')
	{
		cout << "Erro: estado nao encontrado";
		system("PAUSE");
		return;
	}

	char proxSim;
	int anterior = this->i;
	char lido = this->fita[anterior];
	if(es.direcaoMovimento == 'D') {
		proxSim = this->fita[++this->i];
	} else {
		proxSim = this->fita[--this->i];	
	}
	
	this->fita[anterior] = es.escreve;
	
	string cabecote = "";
	for(int j = 0; j < 20; j++) {
		if (this->i == j)
		{
			cabecote += "v";
		}
		else
		{
			cabecote += " ";
		}
	}
	
	string espaco = "";
	for(int j = 0; j < 5; j++) {
		cout << endl;
		espaco += "  ";
	}
	
	cout << espaco << cabecote << endl;
	cout << espaco << this->fita << endl;
	cout << espaco << "Estado: " << es.proximoEstado << "   Lendo: " << this->fita[this->i] << endl;
	sleep(500); 
	
	if (this->fita.empty() || es.proximoEstado == 'F')
	{
		cout << endl << endl;
		cout << espaco << "Sucesso: fita lida com sucesso!" << endl;
		cout << endl << endl;
		return;
	}
	
	this->init(es.proximoEstado, proxSim);	
}
