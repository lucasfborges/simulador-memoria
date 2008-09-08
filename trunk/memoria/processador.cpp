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
     
     // Inicializando ponteiro
     enderecoFisico = (int*) malloc(2*sizeof(int));
          
     // Inicializa a paginação, recebendo o nome do primeiro processo a executar
     nomeProcesso = proManager.iniciarPaginas(memorizu, memManager);     
     
     cout << "Not so good." << endl;
     system("pause");
     do{        
        // Envia o endereço lógico, recebe o físico - ou um sinal de erro neste
        enderecoFisico = memManager.resolverEndereco(endereco, nomeProcesso);  
                   
        // Se a página não foi encontrada, carrega páginas para a memória física      
        if(enderecoFisico[0] == -1){
           cout << "Pretty bad actually." << endl;
     system("pause");
           
           proManager.carregarPaginas(memorizu, nomeProcesso, endereco, memManager);
           std::cout << "Troca de páginas concluida." << endl;
           system("pause");
           
        // Senão, carrega a instrução da memória física e "executa"
        }else{
            cout << "For wut?" << endl;
            
            cout << memorizu->memoriaFisica[0].processo << " Soah  " << endl;
              
              
           cout << "thanks for this: " << enderecoFisico[0] << "  e isso: " << enderecoFisico[1] << endl;
     system("pause");
              
           sidePagina = memorizu->memoriaFisica[enderecoFisico[0]];
           instrucao = sidePagina.comando[enderecoFisico[1]];
           // "execução" de instrução
           std::cout << instrucao << endl << endl;               
           system("pause");
           endereco++;
        }
     }while(instrucao != "finito!");     
     system("pause");
};
