#include "processador.h"
#include <iostream>

using namespace std;


processador::processador(memorias *alocar){   
   memorizu = alocar;   
   endereco = 0;
};                

void processador::run(){
     string instrucao;     
     
     cout << "Im fine, thanks." << endl;
     system("pause");
     
     nomeProcesso = proManager.iniciarPaginas(memorizu);
     
     do{
        instrucao = memManager.resolverEndereco(endereco, nomeProcesso);
        if(instrucao == "sem paginas"){
           proManager.carregarPaginas(memorizu, nomeProcesso, endereco);
           std::cout << "Troca de páginas concluida." << endl;
           system("pause");
        }else{
           std::cout << instrucao << endl << endl;               // execução de instrução
           endereco++;
        }
     }while(instrucao != "finito!");     
     system("pause");
};
