#ifndef GERENCADORMEMORIA_H_
#define GERENCADORMEMORIA_H_

#include <list>
#include "pagina.h"
#include "memorias.h"

class gerenciadorMemoria{              
	public:		
        //static map<int, int>  hashTable;
        
        //m�todo de tradu��o endere�o l�gico X f�sico		
        string resolverEndereco(int endereco, string processoAtivo);         
};
#endif
