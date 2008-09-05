#ifndef GERENCIADORPROCESSOS_H_
#define GERENCIADORPROCESSOS_H_

#include <iostream>
#include "memorias.h"

using namespace std;

class gerenciadorProcessos{
      public:
             string iniciarPaginas(memorias alocadas);      
             void carregarPaginas(string nomeProcesso);          // não inclui endereço pelo fato dessa 'demo' usar apenas um processo
            
      
};
#endif
