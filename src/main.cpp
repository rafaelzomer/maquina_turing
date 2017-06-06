#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string.h>
#include <stdio.h>
#include "maquina.h"
#include "operacoes/multiplicacao.h"
#include "operacoes/subtracao.h"
#include "operacoes/soma.h"
#include "operacoes/divisao.h"

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
	cout << "5 - Entrar com maquina" << endl;
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
		}
		
	}
	while(dado.compare("0"));
}

void entra(string titulo, string *fita) {
	cout << "Informe "<< titulo << ": " << endl;
	cin >> *fita; 
}

void programa() {
	int opcao;	
	char inicial = 'K';
	char final = 'F';
	string fita, ini, fim;
	maquina *maq;
	
	vector<string> *dados = new vector<string>();
	do{
		menu();
        cin >> opcao;
        dados->push_back("");
        switch(opcao){
        	case 1:
        		//Se dados for vazio, pega programação fixa
        		if(dados->at(0)==""){
        			soma::gerar(dados, &inicial, &final);
				}
				
				maq = new maquina(dados, inicial, final);
				entra("fita", &fita);
				maq->ler(fita);
				break;  
			case 2:
				//Se dados for vazio, pega programação fixa
        		if(dados->at(0)==""){
					subtracao::gerar(dados, &inicial, &final);
				}	
				
				maq = new maquina(dados, inicial, final);
				entra("fita", &fita);
				maq->ler(fita);
				break;   
			case 3:
				//Se dados for vazio, pega programação fixa
        		if(dados->at(0)==""){
					divisao::gerar(dados, &inicial, &final);
				}	
				
				maq = new maquina(dados, inicial, final);
				entra("fita", &fita);
				maq->ler(fita);
				break; 	
			case 4:
				//Se dados for vazio, pega programação fixa
        		if(dados->at(0)==""){
					multiplicacao::gerar(dados, &inicial, &final);
				}		
					
				maq = new maquina(dados, inicial, final);
				entra("fita", &fita);
				maq->ler(fita);
				break;
           	case 5:
              	entradados(dados);
            	entra("inicial", &ini);
            	entra("final", &fim);
				maq = new maquina(dados, ini[0], fim[0]);
            	entra("fita", &fita);
	            maq->ler(fita);
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




