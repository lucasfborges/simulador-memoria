#include <list>
#include "pagina.h"

class memorias{       
	public:
		 int inserirPagina(pagina alocando);	
		
	private:
         std::list<pagina> memoriaVirtual;
		 std::list<pagina> memoriaFisica;
};
