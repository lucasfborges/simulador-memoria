#include "gerenciadorProcessos.h"
#include "memorias.h"
#include <vector>

string gerenciadorProcessos::iniciarPaginas(memorias *memIniciadas){
       int estado = memIniciadas->estadoFisica;       
       string primeiroProcesso, processoCorrente;
       pagina sidePagina;
              
       // retira-se a primeira página da lista da memória virtual
       sidePagina = memIniciadas->memoriaVirtual[0];
       
       // retira-se o nome do processo dessa página, que será o primeiro a executar
       primeiroProcesso = sidePagina.processo;
       
       // adquiri-se o nome do processo corrente (útil se houvesse mais de um...)
       processoCorrente = primeiroProcesso;       
       
       // alocação de páginas da memória virtual para a física       
       while(estado < memIniciadas->limiteFisica  &&  estado < memIniciadas->memoriaVirtual.size()){
          sidePagina = memIniciadas->memoriaVirtual[estado];
          
          // checa se a página em questão ainda pertence ao mesmo processo
          if(sidePagina.processo != processoCorrente){
             break;                                 
          }else{
             // insere página da memória virtual na física
             memIniciadas->memoriaFisica[estado] =  memIniciadas->memoriaVirtual[estado];
             
             // [Check] Atualizar o estado da tabela de tradução do gerenciador de memória
             estado++;             
          }
       }       
       memIniciadas->estadoFisica = estado;       
       
       return primeiroProcesso;       
};

void gerenciadorProcessos::carregarPaginas(memorias *realocar, string nomeProcesso, int endereco){
     pagina sidePagina;
     
     int j=0, ultimaPagina;
     
     // definindo a última página desse processo disponível na memória física
     ultimaPagina = endereco / sidePagina.tamanhoPagina;
     
     for (; j < realocar->limiteFisica; j++, ultimaPagina++){
          sidePagina = realocar->memoriaVirtual[ultimaPagina];
          
          // checa se a página em questão ainda pertence ao mesmo processo
          if(sidePagina.processo != nomeProcesso){
             break;                                 
          }else{
             // insere página da memória virtual na física
             realocar->memoriaFisica[j] = realocar->memoriaVirtual[ultimaPagina];
             
             // [Check] Atualizar o estado da tabela de tradução do gerenciador de memória            
          }          
     }       
};
