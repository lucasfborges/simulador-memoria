#include "processador.h"
#include <iostream>

using namespace std;


processador::processador(memorias *alocar){   
   memorizu = alocar;   
   endereco = 0;
};                

void processador::run(){

     string instrucao = "finito!";     
     int *enderecoFisico;
     pagina sidePagina;
     
     cout << "Im fine, thanks." << endl;
     system("pause");
     
     // Inicializa a pagina��o, recebendo o nome do primeiro processo a executar
     nomeProcesso = proManager.iniciarPaginas(memorizu);     
     do{
        // Envia o endere�o l�gico, recebe o f�sico - ou um sinal de erro neste
        enderecoFisico = memManager.resolverEndereco(endereco, nomeProcesso);  
        
        // Se a p�gina n�o foi encontrada, carrega p�ginas para a mem�ria f�sica      
        if(enderecoFisico[0] == -1){
           proManager.carregarPaginas(memorizu, nomeProcesso, endereco);
           std::cout << "Troca de p�ginas concluida." << endl;
           system("pause");
           
        // Sen�o, carrega a instru��o da mem�ria f�sica e "executa"
        }else{
           sidePagina = memorizu->memoriaFisica[enderecoFisico[0]];
           instrucao = sidePagina.comando[enderecoFisico[1]];
           // "execu��o" de instru��o
           std::cout << instrucao << endl << endl;               
           endereco++;
        }
     }while(instrucao != "finito!");     
     system("pause");
};
