Nosso simulador de gerenciador de memória será programado em C++.

> Utilizaremos uma memória física simulada de 256MB e frames de 40Kb. A memória virtual será de 512MB. Utilizaremos Np processos para simular o funcionamento do gerenciador de memória.

> Nossa memória física simulada será representada por um vetor associativo de Vf posições, sendo cada posição o equivalente a um frame. O identificador de cada posição do vetor será o hexadecimal correspondente à primeira posição de memória daquele frame. (ex. se o frame é composto por 20 posições de memória, o primeiro frame será representado no vetor por "hx0000", o segundo por "hx0014", o terceiro por "hx0028", e assim por diante).



> Nosso processo será representado por um vetor de j posições, cada uma representando uma linha de código (cada linha contendo h KB).


> O simulador de memória virtual paginada simulará a memória física através de um vetor de N posições. A memória virtual será simulada através de um vetor de 2N posições. Uma classe contendo uma quantidade X de variáveis string definirão uma página. Cada uma destas variáveis string armazenarão uma representação de linha de comando. Somente um processo será simulado com este trabalho.


> A execução desse processo se dará da maneira usual, cada página na memória física será executado em sequência por um tempo pré-determinado, controlado através das filas de pronto, execução e bloqueado. Caso a execução de uma página exija o acesso a outra página que não está alocada na memória física, o método de troca de página irá buscar na memória virtual a página ausente. Este processo de troca irá implicar na manipulação do bit de presença da página, simulada por um atributo int da classe que define as páginas.


> O algoritmo escolhido para a troca de página é o FIFO, que consiste em uma fila, com as páginas inseridas na ordem em que foram sendo alocadas na memória fisica. O algoritmo FIFO define que a página mais antiga será removida da memória física para que seja colocada uma nova página previamente armazenada na memória virtual. Para a implementação deste algoritmo, o simulador contará com uma fila, que armazenará apenas o identificador de cada página, na sequência em que são alocadas na memória física.

Nosso vetor de interrupção funcionará para redirecionar o programa para a rotina correspondente, no caso a rotina para tratamento de "falta de páginas". Quando a página em execução necessitar de uma página que não se encontra na memória principal, essa rotina deve lidar com a retirada de uma ou mais páginas da memória e a inserção das páginas necessárias.