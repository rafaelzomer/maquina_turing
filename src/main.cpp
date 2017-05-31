#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string.h>
#include <stdio.h>
#include "maquina.h"
#include "operacoes/multiplicacao.h"

using namespace std;

void menu(){
	system("cls");
	cout << endl;
	cout << "-------- Escolha uma opcao --------" << endl;
	cout << endl;
	cout << "1 - Soma" << endl;
	cout << "2 - Subtracao" << endl;
	cout << "3 - Divisao" << endl;
	cout << "4 - Multiplicacao" << endl;
	cout << "0 - Sair" << endl;
	cout <<endl;
}

void entradados(vector<string> *dados) {
	string dado;
	do{
		cout << "Informe o estado: " << endl;	
		cout << "(Padrao: 0,A=1,A,D)" << endl;
		cin >> dado;
		
		
		if(dado.compare("0")){
			dados->push_back(dado);
			
//			lin = dados[0];
//			col = dados[2];
//			es.proximoEstado = dados[4];
//			es.escreve = dados[6];
//			es.direcaoMovimento = dados[8];
//			
//			linhas[lin][col] = es;	
		}
		
	}
	while(dado.compare("0"));
}

void programa() {
	int opcao;
	vector<string> *dados = new vector<string>();
	maquina *maq = new maquina();
	do{
		menu();
        cin >> opcao;
        
        switch(opcao){
           	case 1:
              entradados(dados);
              break;  
			case 4:
              multiplicacao::gerar(dados);
              maq->ler(dados);
              break;        
    	}
		system("PAUSE"); 
    } while(opcao != 0);
}


int main()
{
     //inicia o programa
    programa();  
    return 0;
}

//struct estado{
//	char proximoEstado, escreve, direcaoMovimento; 
//};
//
//map<char, map<char, estado> > linhas;
//string fita;
//int i; 
//
//void ler(char est, char simbolo){
//	estado es = linhas[est][simbolo];
//	
//	char proxSim;
//	if(es.direcaoMovimento == 'D') {
//		proxSim = fita[++i];
//	} else {
//		proxSim = fita[--i];	
//	}
//	fita[i] = es.escreve;
//	
//	cout << fita;
//	
//	ler(es.proximoEstado, proxSim);	
//}
//
//void entraDados(){
//	
//	string dados;
//	estado es;
//	char lin, col, simboloIni;
//   
//	
//	do{
//		cout << "Informe o estado: " << endl;	
//		cout << "(Padrao: 0,A=1,A,D)" << endl;
//		cin >> dados;
//		
//		
//		if(dados.compare("0")){
//			//d.push_back(dados);              0,A=1,A,D
//			
//			lin = dados[0];
//			col = dados[2];
//			es.proximoEstado = dados[4];
//			es.escreve = dados[6];
//			es.direcaoMovimento = dados[8];
//			
//			linhas[lin][col] = es;	
//		}
//		
//	}
//	while(dados.compare("0"));
//	
//	cout << "Informe o simbolo inicial: " << endl;	
//	cin >> simboloIni;
//	
//	cout << "Informe a fita: " << endl;	
//	cin >> fita;
//	
//	i = 0;
//	ler('0', simboloIni);
//	
//}
//
//
//main(){
//int opcao=-1,nr=0;
//	char temp='N';
//	/*
//	while(opcao != 9){
//		system("cls");
//		cout << endl;
//		cout << "-------- Escolha uma opcao --------" << endl;cout << endl;
//		cout << "1 - Soma" << endl;
//		cout << "2 - Subtracao" << endl;
//		cout << "3 - Divisao" << endl;
//		cout << "4 - Multiplicacao" << endl;
//		cout << "0 - Sair" << endl;
//		cout <<endl;
//	}*/
//	
//	entraDados();
//	
//	system("pause");
//	return 0;
//	
//	
//}




