#include <list>
#include "pagina.h"

class gerenciadorMemoria{
       
    // (est�tica) lista mapeando a p�gina de um processo � lista em mem�rias
              
	public:
		//m�todo de tradu��o endere�o l�gico X f�sico
		int criarProgramas(string nome, int tamanho);
		string resolverEndereco(int endereco);
		
	private:
         memorias memorias;
         
};
