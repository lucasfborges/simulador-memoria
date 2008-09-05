#ifndef GERENCADORMEMORIA_H_
#define GERENCADORMEMORIA_H_

#include <list>
#include "pagina.h"
#include "memorias.h"

class gerenciadorMemoria{              
	public:		
        //static map<int, int>  hashTable;
        
        //método de tradução endereço lógico X físico		
        string resolverEndereco(int endereco, string processoAtivo);         
};
#endif
