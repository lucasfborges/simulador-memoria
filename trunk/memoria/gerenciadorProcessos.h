#ifndef GERENCIADORPROCESSOS_H_
#define GERENCIADORPROCESSOS_H_

#include <iostream>
#include "memorias.h"

using namespace std;

class gerenciadorProcessos{
      public:
             string iniciarPaginas(memorias *memIniciadas);      
             void carregarPaginas(memorias *realocar, string nomeProcesso, int endereco);          // n�o inclui endere�o pelo fato dessa 'demo' usar apenas um processo            
      
      private:
              memorias tabela;
      
};
#endif
