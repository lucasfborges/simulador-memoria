/*
 * ESQUEMA DE OPERA��O
 * O processador, ao solicitar acesso � uma posi��o de mem�ria, envia um endere�o virtual
 * para o gerenciador de mem�ria. O gerenciador retorna para ele o endere�o f�sico
 * associado ao endere�o virtual.
 * Esta classe tamb�m possui m�todos para que o gerenciador de processos possa
 * atualizar a tabela de p�ginas quando ela realizar a troca de p�ginas.
 */

#ifndef GERENCIADORMEMORIA_H_
#define GERENCIADORMEMORIA_H_

#include <list>
#include "pagina.h"
#include "memorias.h"
#include "coordenadas.h"
#include <map>

class gerenciadorMemoria{              
	public:
        
		//tabela de p�ginas
		std::map<int,int> tabela;
		
        //m�todo de tradu��o endere�o l�gico X f�sico
        coordenadas resolverEndereco(int endereco, string processoAtivo);
        
        //m�todo para atualizar tabela
        //par�metros: pagina que saiu da memoria fisica, pagina que foi
        //colocada na mem�ria fisica, endere�o(fisico ou virtual)?
        void atualizaTabela(int pagina_saiu, int pagina_colocada, int endereco);
        
        // Mesmo que anterior, mas apenas insere
        void iniciaTabela(int pagina_colocada, int endereco);
        
};
#endif
