#ifndef PROCESSADOR_H_
#define PROCESSADOR_H_

#include "gerenciadorMemoria.h"
#include "gerenciadorProcessos.h"
#include <list>

class processador{
      
      public:
             processador(memorias controle);
             void run();      
             
             void carregarEstado(int endereco);             
             std::string carregarInstrucao(int endereco);
             int carregarPaginas(std::string processo);             
             
      private:
             int endereco;
             std::string nomeProcesso;             

             gerenciadorMemoria memManager;
             gerenciadorProcessos proManager;
             memorias memoriaz;
};
#endif
