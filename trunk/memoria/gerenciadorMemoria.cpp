#include "gerenciadorMemoria.h"
#include "pagina.h"
#include "coordenadas.h"

//lance da divisao
//retorna -1 na posi��o 0 da struct caso o endere�o nao esteja mapeado
//exemplo insercao no mapa:
//tabela.insert(std::pair<int,int>(2,7));
coordenadas gerenciadorMemoria::resolverEndereco(int endereco, string processoAtivo){
	int paginaCorrente, linhaCorrente;	
	coordenadas resultado;
	
	pagina obj;	
	paginaCorrente = endereco/obj.tamanhoPagina;	
	linhaCorrente =  endereco%obj.tamanhoPagina;
	
	// Imprime p�gina e linha
	cout << "Numero da pagina: " << tabela[0] << endl << "Numero da linha: " << linhaCorrente << endl << endl;	
	
	std::map<int,int>::iterator itr = tabela.lower_bound(paginaCorrente);
	std::map<int,int>::key_compare cmp = tabela.key_comp();
        
    //verifica se o endere�o esta mapeado na memoria fisica
    //existe:   
    if(tabela.end() != itr && !cmp(paginaCorrente,(*itr).first)){
    	//quociente da divisao
    	cout << "Encontraram-me" << endl;
        system("pause");
    	
    	resultado.coord1 = tabela[(endereco/obj.tamanhoPagina)];
    //nao existe:
}    else
    	resultado.coord1 = -1;
    	
    //resto da divisao
    resultado.coord2 = (endereco%obj.tamanhoPagina);
    
    return resultado;
};


void gerenciadorMemoria::atualizaTabela(int pagina_saiu, int pagina_colocada, int endereco){
	//itr - � atribuida a ela o par cuja chave � a pagina que saiu da memoria principal
	std::map<int,int>::iterator itr = tabela.lower_bound(pagina_saiu);
     
	//apaga par que itr aponta
	tabela.erase(itr);
     
	//insere novo par no mapa
	tabela.insert(std::pair<int,int>(pagina_colocada,endereco));
};

void gerenciadorMemoria::iniciaTabela(int pagina_colocada, int endereco){
	//insere novo par no mapa
	tabela.insert(std::pair<int,int>(pagina_colocada,endereco));
};
