#include "gerenciadorProcessos.h"
#include "memorias.h"
#include <vector>

string gerenciadorProcessos::iniciarPaginas(memorias *memIniciadas){
       int estado = memIniciadas->estadoFisica;       
       string primeiroProcesso, processoCorrente;
       pagina sidePagina;
              
       // retira-se a primeira p�gina da lista da mem�ria virtual
       sidePagina = memIniciadas->memoriaVirtual[0];
       
       // retira-se o nome do processo dessa p�gina, que ser� o primeiro a executar
       primeiroProcesso = sidePagina.processo;
       
       // adquiri-se o nome do processo corrente (�til se houvesse mais de um...)
       processoCorrente = primeiroProcesso;       
       
       // aloca��o de p�ginas da mem�ria virtual para a f�sica       
       while(estado < memIniciadas->limiteFisica  &&  estado < memIniciadas->memoriaVirtual.size()){
          sidePagina = memIniciadas->memoriaVirtual[estado];
          
          // checa se a p�gina em quest�o ainda pertence ao mesmo processo
          if(sidePagina.processo != processoCorrente){
             break;                                 
          }else{
             // insere p�gina da mem�ria virtual na f�sica
             memIniciadas->memoriaFisica[estado] =  memIniciadas->memoriaVirtual[estado];
             
             // [Check] Atualizar o estado da tabela de tradu��o do gerenciador de mem�ria
             estado++;             
          }
       }       
       memIniciadas->estadoFisica = estado;       
       
       return primeiroProcesso;       
};

void gerenciadorProcessos::carregarPaginas(memorias *realocar, string nomeProcesso, int endereco){
     pagina sidePagina;
     
     int j=0, ultimaPagina;
     
     // definindo a �ltima p�gina desse processo dispon�vel na mem�ria f�sica
     ultimaPagina = endereco / sidePagina.tamanhoPagina;
     
     for (; j < realocar->limiteFisica; j++, ultimaPagina++){
          sidePagina = realocar->memoriaVirtual[ultimaPagina];
          
          // checa se a p�gina em quest�o ainda pertence ao mesmo processo
          if(sidePagina.processo != nomeProcesso){
             break;                                 
          }else{
             // insere p�gina da mem�ria virtual na f�sica
             realocar->memoriaFisica[j] = realocar->memoriaVirtual[ultimaPagina];
             
             // [Check] Atualizar o estado da tabela de tradu��o do gerenciador de mem�ria            
          }          
     }       
};
