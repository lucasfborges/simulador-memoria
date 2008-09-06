/*
 * ESQUEMA DE OPERAÇÃO
 * O processador, ao solicitar acesso à uma posição de memória, envia um endereço virtual
 * para o gerenciador de memória. O gerenciador retorna para ele o endereço físico
 * associado ao endereço virtual.
 */

#ifndef GERENCIADORMEMORIA_H_
#define GERENCIADORMEMORIA_H_

#include <list>
#include "pagina.h"
#include "memorias.h"

class gerenciadorMemoria{              
	public:
        
		//tabela de páginas
		map<int,int> tabela;
		
        //método de tradução endereço lógico X físico
        string resolverEndereco(int endereco, string processoAtivo);
        
        //método para atualizar tabela
        void atualizaTabela();
};
#endif
