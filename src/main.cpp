#include <iostream>
#include <stdlib.h>
#include <vector>
#include <map>
#include <string.h>
#include <stdio.h>
using namespace std;

struct estado{
	char proximoEstado, escreve, direcaoMovimento; 
};

map<char, map<char, estado> > linhas;
string fita;
int i; 

void ler(char est, char simbolo){
	estado es = linhas[est][simbolo];
	
	char proxSim;
	if(es.direcaoMovimento == 'D') {
		proxSim = fita[++i];
	} else {
		proxSim = fita[--i];	
	}
	fita[i] = es.escreve;
	
	cout << fita;
	
	ler(es.proximoEstado, proxSim);	
}

void entraDados(){
	
	string dados;
	estado es;
	char lin, col, simboloIni;
   
	
	do{
		cout << "Informe o estado: " << endl;	
		cout << "(Padrao: 0,A=1,A,D)" << endl;
		cin >> dados;
		
		
		if(dados.compare("0")){
			//d.push_back(dados);              0,A=1,A,D
			
			lin = dados[0];
			col = dados[2];
			es.proximoEstado = dados[4];
			es.escreve = dados[6];
			es.direcaoMovimento = dados[8];
			
			linhas[lin][col] = es;	
		}
		
	}
	while(dados.compare("0"));
	
	cout << "Informe o simbolo inicial: " << endl;	
	cin >> simboloIni;
	
	cout << "Informe a fita: " << endl;	
	cin >> fita;
	
	i = 0;
	ler('0', simboloIni);
	
}


main(){
int opcao=-1,nr=0;
	char temp='N';
	/*
	while(opcao != 9){
		system("cls");
		cout << endl;
		cout << "-------- Escolha uma opcao --------" << endl;cout << endl;
		cout << "1 - Soma" << endl;
		cout << "2 - Subtracao" << endl;
		cout << "3 - Divisao" << endl;
		cout << "4 - Multiplicacao" << endl;
		cout << "0 - Sair" << endl;
		cout <<endl;
	}*/
	
	entraDados();
	
	system("pause");
	return 0;
	
	
}




