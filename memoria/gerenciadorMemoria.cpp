#include "gerenciadorMemoria.h"
#include "pagina.h"

//lance da divisao
int* gerenciadorMemoria::resolverEndereco(int endereco, string processoAtivo){
       int resultado[2];
       
       pagina obj;// = new pagina();
       
       //quociente da divisao
       resultado[0] = tabela[(endereco/obj.tamanhoPagina)];
       //resto da divisao
       resultado[1] = (endereco%obj.tamanhoPagina);
       
       return resultado;
       //return "finito!";
};
