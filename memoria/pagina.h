#ifndef PAGINA_H_
#define PAGINA_H_

#include <list>
#include <iostream>

class pagina{

	public:
        pagina(){
           pagina::tamanhoPagina = 50;
        }

        static int tamanhoPagina;               

        std::list<std::string> comando;
		std::string processo;
        int ordenacao;

};

//

#endif
 
