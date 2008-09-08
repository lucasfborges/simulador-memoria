#include <iostream>
#include "pagina.h"
#include "memorias.h"
#include "processador.h"

using namespace std;

int main(){
    int processos, linhas, j=0, i=0, h, sequencia=0;    
    string nomeProcesso, nomeInstrucao;
    
    memorias *memorizu = new memorias();
    pagina alocada, troca;
            
	cout << "hello world" << endl;	
	cout << "Digite o n�mero de processos a executar: ";
	cin >> processos;
	
	// Criando os programas
    for(; j< processos; j++){
          // Zerando vari�veis          
          sequencia=0; 
          
          // Recolhendo dados sobre os programas/processos          
          cout << endl << endl << "Digite o nome do processo: ";
          cin >> nomeProcesso;
          cout << endl << "Digite o n�mero de 'linhas' do processo: ";
          cin >> linhas;
                             
          // Lan�ando as p�ginas do programa na mem�ria
          while(i < linhas){             
             alocada.processo = nomeProcesso;
             alocada.ordenacao = sequencia;             
             
             // Alocando instru��es � p�gina
             for(h=0; h < alocada.tamanhoPagina && i < linhas; h++, i++){                 
                 if(h+1 == alocada.tamanhoPagina){
                   nomeInstrucao = "finito!";
                 }else{                        
                    nomeInstrucao = "Instrucao ";// + i;
                 }
                 alocada.comando.push_back(nomeInstrucao); 
             }
             sequencia++;                
             memorizu->memoriaVirtual.push_back(alocada);      
             memorizu->memoriaFisica.push_back(alocada);           // Rever essa id�ia...                         
             alocada.comando.clear();
          }                   
    }
    
    // Construindo processador, inserindo-lhe as mem�rias e rodando-o
    processador processar(memorizu);
    processar.run();
    
    return 0;	
};
