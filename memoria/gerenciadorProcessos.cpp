#include "gerenciadorProcessos.h"
#include "gerenciadorMemoria.h"
#include "memorias.h"
#include "pagina.h"
#include <vector>

string gerenciadorProcessos::iniciarPaginas(memorias *memIniciadas, gerenciadorMemoria tabela){
       int estado = memIniciadas->estadoFisica;       
       string primeiroProcesso, processoCorrente;
       pagina sidePagina;
       
       vector<pagina> holding;
       
              
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
             memIniciadas->memoriaFisica[estado] = memIniciadas->memoriaVirtual[estado];
             
             // Atualizar o estado da tabela de tradu��o do gerenciador de mem�ria
             tabela.iniciaTabela(estado, estado);
             estado++;             
          }
       }       
       memIniciadas->estadoFisica = estado;       
       
       return primeiroProcesso;       
};

void gerenciadorProcessos::carregarPaginas(memorias *realocar, string nomeProcesso, int endereco, gerenciadorMemoria tabela){
     pagina sidePagina;
     
     int j=0, ultimaPagina, paginaSai, paginaEntra;
     
     // definindo a �ltima p�gina desse processo dispon�vel na mem�ria f�sica
     ultimaPagina = endereco / sidePagina.tamanhoPagina;
     
     for (; j < realocar->limiteFisica && ultimaPagina < realocar->finalVirtual; j++, ultimaPagina++){
          sidePagina = realocar->memoriaVirtual[ultimaPagina];
          
          cout << "Roll mr ultima:" << ultimaPagina << "  e final Virtual: " << realocar->finalVirtual << endl;
           system("pause");
          
          // checa se a p�gina em quest�o ainda pertence ao mesmo processo
          if(sidePagina.processo != nomeProcesso){
             break;                                 
          }else{
             // insere p�gina da mem�ria virtual na f�sica
             paginaSai = realocar->memoriaFisica[j].ordenacao;
             paginaEntra = realocar->memoriaVirtual[ultimaPagina].ordenacao;
             
             realocar->memoriaFisica[j] = realocar->memoriaVirtual[ultimaPagina];
             
             cout << "Sai: " << paginaSai << "  e entra: " << paginaEntra << endl;
           system("pause");
             
             
             // Atualizar o estado da tabela de tradu��o do gerenciador de mem�ria            
             tabela.atualizaTabela(paginaSai, paginaEntra, j);
             cout << "Roll mr." << endl;
           system("pause");
          }          
     }       
};
