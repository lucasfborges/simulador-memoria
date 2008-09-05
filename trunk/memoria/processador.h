#include <list>

class processador{
      
      public:
             processador(gerenciadorMemoria controle);
             void carregarEstado(int endereco);             
             string carregarInstrucao(int endereco);
             int carregarPaginas(string processo);             
             
      private:
              int endereco;
              string nomeProcesso;             
              
};
