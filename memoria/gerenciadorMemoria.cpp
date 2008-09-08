#include "gerenciadorMemoria.h"
#include "pagina.h"

//lance da divisao
//retorna -1 na posi��o 0 do vetor caso o endere�o nao esteja mapeado
//exemplo insercao no mapa:
//tabela.insert(std::pair<int,int>(2,7));
int* gerenciadorMemoria::resolverEndereco(int endereco, string processoAtivo){
	int resultado[2], paginaCorrente;	
	
	pagina obj;// = new pagina();
	
	paginaCorrente = endereco/obj.tamanhoPagina;
	
	cout << "Im alive.. " << tabela[0] << tabela[1] << tabela [2] << " e.. " << paginaCorrente << endl;
     system("pause");
	
	
	
	std::map<int,int>::iterator itr = tabela.lower_bound(paginaCorrente);
	std::map<int,int>::key_compare cmp = tabela.key_comp();
        
    cout << "Im fine, first." << endl;
     system("pause");
    //verifica se o endere�o esta mapeado na memoria fisica
    //existe:   
    if(tabela.end() != itr && !cmp(paginaCorrente,(*itr).first)){
    	//quociente da divisao
    	cout << "Im fine, thanks." << endl;
     system("pause");
    	
    	resultado[0] = tabela[(endereco/obj.tamanhoPagina)];
    //nao existe:
}    else
    	resultado[0] = -1;
    	
    //resto da divisao
    resultado[1] = (endereco%obj.tamanhoPagina);
    
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
