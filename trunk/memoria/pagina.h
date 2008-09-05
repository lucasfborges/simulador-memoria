#ifndef PAGINA_H_
#define PAGINA_H_

#include <list>
#include <iostream>

using namespace std;

class pagina{        
 
	public:           
         pagina(){
            tamanhoPagina = 50;                  
         }                   
 
        int tamanhoPagina;               
        
        list<string> comando;
		string processo;
        int ordenacao;
        
};
#endif
 
