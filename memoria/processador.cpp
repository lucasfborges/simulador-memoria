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
     
     // Inicializa a paginação, recebendo o nome do primeiro processo a executar
     nomeProcesso = proManager.iniciarPaginas(memorizu);     
     do{
        // Envia o endereço lógico, recebe o físico - ou um sinal de erro neste
        enderecoFisico = memManager.resolverEndereco(endereco, nomeProcesso);  
        
        // Se a página não foi encontrada, carrega páginas para a memória física      
        if(enderecoFisico[0] == -1){
           proManager.carregarPaginas(memorizu, nomeProcesso, endereco);
           std::cout << "Troca de páginas concluida." << endl;
           system("pause");
           
        // Senão, carrega a instrução da memória física e "executa"
        }else{
           sidePagina = memorizu->memoriaFisica[enderecoFisico[0]];
           instrucao = sidePagina.comando[enderecoFisico[1]];
           // "execução" de instrução
           std::cout << instrucao << endl << endl;               
           endereco++;
        }
     }while(instrucao != "finito!");     
     system("pause");
};
