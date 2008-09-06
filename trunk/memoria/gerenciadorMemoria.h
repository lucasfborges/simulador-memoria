/*
 * ESQUEMA DE OPERAÇÃO
 * O processador, ao solicitar acesso à uma posição de memória, envia um endereço virtual
 * para o gerenciador de memória. O gerenciador retorna para ele o endereço físico
 * associado ao endereço virtual.
 * Esta classe também possui métodos para que o gerenciador de processos possa
 * atualizar a tabela de páginas quando ela realizar a troca de páginas.
 */

#ifndef GERENCIADORMEMORIA_H_
#define GERENCIADORMEMORIA_H_

#include <list>
#include "pagina.h"
#include "memorias.h"
#include <map>

class gerenciadorMemoria{              
	public:
        
		//tabela de páginas
		std::map<int,int> tabela;
		
        //método de tradução endereço lógico X físico
        int* resolverEndereco(int endereco, string processoAtivo);
        
        //método para atualizar tabela
        void atualizaTabela();
};
#endif
