#include <iostream>
#include "pagina.h"

int main(){
    int processos, linhas, j=0, i=0, h=0, sequencia=0;    
    string nomeProcesso, nomeInstrucao;
    
    memorias memorias = new memorias();
    pagina alocada;
        
	std::cout << "hello world" << std::endl;	
	std::cout << "Digite o número de processos a executar:" << std::endl;
	std::cin >> processos;
	
	// Criando os programas
    for(; j< processos; j++){
          // Zerando variáveis          
          sequencia=0
          pagina alocada = NULL;
          
          // reiniciando variável
          pagina alocada = new pagina();
          
          // Recolhendo dados sobre os programas/processos          
          std::cout << "Digite o nome do processo: ";
          std::cin >> nomeProcesso;
          std::cout << "Digite o número de 'linhas' do processo: ";
          std::cin >> linhas;
          
          // Lançando as páginas do programa na memória
          while(i < linhas){
             alocada.processo = nomeProcesso;
             alocada.ordenacao = sequencia;
             
             // Alocando instruções à página
             for(h=0; h < pagina.tamanhoPagina && i < linhas; h++, i++){
                 nomeInstrucao << "Instrucao " << i;
                 alocada.comando.push_back(nomeInstrucao);                
                }
                sequencia++;
                pagina alocada = new pagina();
                memorias.inserirPagina(alocada);                
          }
          
          
          
          if( memorias.inserirPagina(    ){
             std::cout << "Erro durante a inserção.";
             break;              
          }
          
	
	
	
	
};
