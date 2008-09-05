#ifndef GERENCIADORPROCESSOS_H_
#define GERENCIADORPROCESSOS_H_

#include <iostream>
#include "memorias.h"

class gerenciadorProcessos{
      public:
             std::string iniciarPaginas(memorias alocadas); 
             // não inclui endereço pelo fato dessa 'demo' usar apenas um processo
             void carregarPaginas(std::string nomeProcesso);
            
      
};
#endif
