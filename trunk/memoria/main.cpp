#include <iostream>
#include "pagina.h"
#include "memorias.h"
#include "processador.h"

int main(){
    int processos, linhas, j=0, i=0, h, sequencia=0;    
    string nomeProcesso, nomeInstrucao;
    
    memorias memorizu;// = new memorias();
    pagina alocada;// = new pagina();    
        
	std::cout << "hello world" << std::endl;	
	std::cout << "Digite o n�mero de processos a executar: ";
	std::cin >> processos;
	
	// Criando os programas
    for(; j< processos; j++){
          // Zerando vari�veis          
          sequencia=0;          
          
          // Recolhendo dados sobre os programas/processos          
          std::cout << endl << endl << "Digite o nome do processo: ";
          std::cin >> nomeProcesso;
          std::cout << endl << "Digite o n�mero de 'linhas' do processo: ";
          std::cin >> linhas;
          
          // Lan�ando as p�ginas do programa na mem�ria
          while(i < linhas){             
             alocada.processo = nomeProcesso;
             alocada.ordenacao = sequencia;
             
             // Alocando instru��es � p�gina
             for(h=0; h < alocada.tamanhoPagina && i < linhas; h++, i++){
                 if(h+1 >= alocada.tamanhoPagina){
                   nomeInstrucao = "finito!";
                 }else{                        
                    nomeInstrucao = "Instrucao " + i;
                 }
                 alocada.comando.push_back(nomeInstrucao);                
             }
             sequencia++;                
             memorizu.memoriaVirtual.push_back(alocada);                             
             //pagina alocada = new pagina();
          }                   
    }
    
    processador processar(memorizu);          
    //processar = new processador(memorias);
    processar.run();
    
    return 0;	
};
