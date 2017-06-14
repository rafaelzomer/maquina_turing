#include <string>
#include <algorithm>
#include <iostream>
#include "estado.h"
#include <map>
#include <vector>
#include "uteis/sleep.h"
#include "uteis/split.h"

using namespace std;

class maquina{
   private:
      int codigo, i = 0, repeticao = 0;
      string fita;
      string fitaInicial;
      string nome;
      string inicial, final;
      vector<char> estados;
      map<string, map<char, estado> > linhas;
      void init(string est, char simbolo);
      bool ehestado(char simbolo);
   
   public:
      maquina(vector<string> *dados, string inicial, string final);
      void ler(string fita);
};

maquina::maquina(vector<string> *dados, string inicial, string final) {
	this->inicial = inicial;
	this->final = final;
	estado es;
	string lin;
	char col; 
  	for(int i = 0; i < dados->size(); i++) {
	  	string dado = dados->at(i);
	  	vector<string> partes = split(dado, "=");
	  	vector<string> p1 = split(partes[0], ",");
	  	vector<string> p2 = split(partes[1], ",");
		lin = p1[0];
		col = p1[1][0];
		es.proximoEstado = p2[0];
		es.escreve = p2[1][0];
		es.direcaoMovimento = p2[2][0];
		
		if (!ehestado(es.escreve)) {
			estados.push_back(es.escreve);
		}
		this->linhas[lin][col] = es;	
	}
}

bool maquina::ehestado(char simbolo){
	for (int j =0; j< estados.size(); j++) {
		if (estados[j] == simbolo)
		{
			return true;
		}
	}
	return false;
}
	
void maquina::ler(string fita){
	fita = fita+"_____________";
	//Acrescenta simbolo inicial caso nao houver
	if (this->fita[0] != this->inicial[0])
	{
		fita = this->inicial + fita;
	}
	//Substitui os espacos por underline
	replace( fita.begin(), fita.end(), ' ', '_');
	this->fitaInicial = fita;
	this->fita = fita;
	this->repeticao = 0;
	this->init(this->inicial, this->inicial[0]);
}

void maquina::init(string est, char simbolo) {
	this->repeticao++;
	
	estado es = this->linhas[est][simbolo];

	if (!ehestado(es.escreve))
	{
		cout << endl << endl << "Erro: maquina de turing mal programada, nada para escrever ";
		return;
	}
	else
	{
		clear_screen();
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
	
	estado proxEs = this->linhas[es.proximoEstado][proxSim];
	
	cout << espaco << cabecote << endl;
	cout << espaco << this->fita << endl;
	cout << espaco << "Estado: " << es.proximoEstado;
	cout << "   Lendo: " << this->fita[this->i];
	cout << "   Escreve: " << proxEs.escreve << endl;
	
	sleep(100); 
	
	if (this->fita.empty() || es.proximoEstado == this->final)
	{
		cout << endl << endl;
		cout << espaco << "Sucesso: fita lida com sucesso!" << endl;
		cout << espaco << "Fita inicial: " << endl;
		cout << espaco << this->fitaInicial << endl;
		
		cout << endl << endl;
		return;
	}
	
	this->init(es.proximoEstado, proxSim);	
}
