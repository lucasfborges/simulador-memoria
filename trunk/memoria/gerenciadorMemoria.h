/*
 * ESQUEMA DE OPERA��O
 * O processador, ao solicitar acesso � uma posi��o de mem�ria, envia um endere�o virtual
 * para o gerenciador de mem�ria. O gerenciador retorna para ele o endere�o f�sico
 * associado ao endere�o virtual.
 */

#ifndef GERENCIADORMEMORIA_H_
#define GERENCIADORMEMORIA_H_

#include <list>
#include "pagina.h"
#include "memorias.h"

class gerenciadorMemoria{              
	public:
        
		//tabela de p�ginas
		map<int,int> tabela;
		
        //m�todo de tradu��o endere�o l�gico X f�sico
        string resolverEndereco(int endereco, string processoAtivo);
        
        //m�todo para atualizar tabela
        void atualizaTabela();
};
#endif
