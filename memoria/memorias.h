#ifndef MEMORIAS_H_
#define MEMORIAS_H_

#include <list>
#include "pagina.h"

class memorias{       
	public:
           std::list<pagina> memoriaVirtual;
		   std::list<pagina> memoriaFisica;
};
#endif
