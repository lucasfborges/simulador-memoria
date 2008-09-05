#include "processador.h"
#include <iostream>

using namespace std;


processador::processador(memorias controle){   
   memoriaz = controle;
   endereco = 0;
};                

void processador::run(){
     string instrucao;     
     
     nomeProcesso = proManager.iniciarPaginas(memoriaz);
     
     do{
        instrucao = memManager.resolverEndereco(endereco);
        if(instrucao == "sem paginas"){
           proManager.carregarPaginas(nomeProcesso);
           std::cout << "Troca de páginas concluida." << endl;
           system("pause");
        }else{
           std::cout << instrucao << endl << endl;               // execução de instrução
           endereco++;
        }
     }while(instrucao != "finito!");     
     system("pause");
};
