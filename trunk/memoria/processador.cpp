#include "processador.h"
#include "gerenciadorMemoria.h"
#include "coordenadas.h"
#include <iostream>

using namespace std;


processador::processador(memorias *alocar){   
   memorizu = alocar;   
   endereco = 0;
};                

void processador::run(){

     string instrucao = "finito!";     
     //int *enderecoFisico;
     pagina sidePagina;     
     coordenadas enderecoFisico;
              
     // Inicializa a pagina��o, recebendo o nome do primeiro processo a executar
     nomeProcesso = proManager.iniciarPaginas(memorizu, memManager);    
     
     do{        
        // Envia o endere�o l�gico, recebe o f�sico - ou um sinal de erro neste
        enderecoFisico = memManager.resolverEndereco(endereco, nomeProcesso);  
                   
        // Se a p�gina n�o foi encontrada, carrega p�ginas para a mem�ria f�sica      
        if(enderecoFisico.coord1 == -1){
           cout << "Pretty bad actually." << endl;
           system("pause");
           
           proManager.carregarPaginas(memorizu, nomeProcesso, endereco, memManager);
           std::cout << "Troca de p�ginas concluida." << endl;
           enderecoFisico.coord1 = 0;
           system("pause");
           
        // Sen�o, carrega a instru��o da mem�ria f�sica e "executa"
        }else{              
              
           //cout << "Pagina que chegou: " << enderecoFisico.coord1 << "  e linha: " << enderecoFisico.coord2 << endl << endl;
           //system("pause");
              
           sidePagina = memorizu->memoriaFisica[enderecoFisico.coord1];
           instrucao = sidePagina.comando[enderecoFisico.coord2];
           // "execu��o" de instru��o
           std::cout << instrucao << endl << endl;               
           system("pause");
           endereco++;
        }
     }while(instrucao != "finito!");     
     cout << endl << endl << "I did it! I got the internets, darn it!!" << endl;
     system("pause");
};
