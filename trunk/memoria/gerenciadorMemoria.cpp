#include "gerenciadorMemoria.h"
#include "pagina.h"

//lance da divisao
//retorna -1 na posição 0 do vetor caso o endereço nao esteja mapeado
//exemplo insercao no mapa:
//tabela.insert(std::pair<int,int>(2,7));
int* gerenciadorMemoria::resolverEndereco(int endereco, string processoAtivo){
	int resultado[2];
	
	std::map<int,int>::iterator itr = tabela.lower_bound(endereco);
	std::map<int,int>::key_compare cmp = tabela.key_comp();
       
    pagina obj;// = new pagina();
    
    //verifica se o endereço esta mapeado na memoria fisica
    //existe:
    if(tabela.end() != itr && !cmp(endereco,(*itr).first))
    	//quociente da divisao
    	resultado[0] = tabela[(endereco/obj.tamanhoPagina)];
    //nao existe:
    else
    	resultado[0] = -1;
    	
    //resto da divisao
    resultado[1] = (endereco%obj.tamanhoPagina);
    
    return resultado;
};


void gerenciadorMemoria::atualizaTabela(int pagina_saiu, int pagina_colocada, int endereco){
	//itr - é atribuida a ela o par cuja chave é a pagina que saiu da memoria principal
	std::map<int,int>::iterator itr = tabela.lower_bound(pagina_saiu);
	
	//apaga par que itr aponta
	tabela.erase(itr);
	
	//insere novo par no mapa
	tabela.insert(std::pair<int,int>(pagina_colocada,endereco));
}
