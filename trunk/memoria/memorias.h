#ifndef MEMORIAS_H_
#define MEMORIAS_H_

#include <list>
#include <iostream>
#include "pagina.h"

using namespace std;

class memorias{       
	public:
           memorias(){
              limiteFisica = 16;
              estadoFisica = 0;
           };           
           
           list<pagina> memoriaVirtual,
                        memoriaFisica;
		   
		   int limiteFisica,
               estadoFisica; 
};
#endif
