#ifndef GERENCADORMEMORIA_H_
#define GERENCADORMEMORIA_H_

#include <list>
#include "pagina.h"
#include "memorias.h"

class gerenciadorMemoria{
       
    // (estática) lista mapeando a página de um processo à lista em memórias
              
	public:
		//método de tradução endereço lógico X físico
		std::string resolverEndereco(int endereco);
		
	private:
         memorias memoriaz;
         
};
#endif
