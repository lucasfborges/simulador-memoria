#ifndef GERENCIADORMEMORIA_H_
#define GERENCIADORMEMORIA_H_

#include <list>
#include "pagina.h"
#include "memorias.h"

class gerenciadorMemoria{
       
    // (est�tica) lista mapeando a p�gina de um processo � lista em mem�rias
              
	public:
		//m�todo de tradu��o endere�o l�gico X f�sico
		string resolverEndereco(int endereco);
		
	private:
         memorias memoriaz;
         
};
#endif
