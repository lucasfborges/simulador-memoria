#include <list>
#include "pagina.h"

class gerenciadorMemoria{
       
    // (estática) lista mapeando a página de um processo à lista em memórias
              
	public:
		//método de tradução endereço lógico X físico
		int criarProgramas(string nome, int tamanho);
		string resolverEndereco(int endereco);
		
	private:
         memorias memorias;
         
};
