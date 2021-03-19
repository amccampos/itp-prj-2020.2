# Projeto da disciplina de ITP - 2020.2

1. Altere o código do bot-exemplo.c (bot.c) com sua própria IA
2. Execute a linha de comando (aba Shell)
   $ node main.js bot

Os comandos entre o bot e o jogo devem ser realizados via entrada e saída padrão.
No início da partida, o jogo envia para o bot as seguintes informações (uma em cada linha):
- Os identificadores de todos os jogadores (bots) separados por espaço
- O identificador do bot (seu identificador)
- As cartas que o bot tem na mão
- A carta que se encontra no topo da pilha de descarte (lixo).

No início de cada rodada, o jogo enviará para todos os bots o identificador do bot que está "na vez" e aguardará uma ação desse bot a ser tomada.

A primeira ação deve obrigatoriamente puxar uma carta, que pode ser do deque de compra ou do topo da pilha de descarte. Porém, se for puxar da pilha, o bot terá que formar um jogo com o que está no topo e as cartas que estão na mão. Fazendo o jogo, ele pegará todas as demais cartas do lixo.

Em seguida, o bot poderá baixar um novo jogo, incluir cartas em jogos existentes ou descartar uma carta no lixo. No momento que descartar, termina sua vez e o próximo bot deve realizar suas ações.

Para realizar uma ação o bot pode enviar para a saída-padrão os seguintes comandos:

- GET_STOCK
  Puxa uma carta do deque de compra.
  Esse comando não tem parâmetro.
  Depois do comando, o bot deve ler da entrada-padrão a carta que puxou.

- GET_DISCARD [ c1 c2 ... ]
  Pega toda a pilha de descarte (lixo).
  Para isso, é necessário fazer um jogo com a carta do topo da pilha.
  [ c1 c2 ... ] são as cartas da mão a serem usadas no jogo.
  Depois do comando, o bot deve ler uma linha com as cartas que se encontravam no lixo.

- MELD_NEW [ c1 c2 ... ]
  Baixa um jogo na mesa.
  [ c1 c2 ... ] são as cartas da mão a serem usadas no jogo.
  Depois do comando, não há dados para ler da entrada-padrão.

- MELD_JOIN ind [ c1 c2 ... ]
  Anexa cartas a um jogo já existente.
  ind é o índice do jogo na ordem em que ele foi criado (1º = 0, 2º = 1...)
  [ c1 c2 ... ] são as cartas da mão a serem anexadas no jogo.
  Depois do comando, não há dados para ler da entrada-padrão.

- DISCARD c
  Descarta uma carta na pilha de descarte (lixo).
  c é a carta da mão que será descartada.
  Depois do comando, não há dados para ler da entrada-padrão.

Todas os comandos são repassados para todos os bots, permitindo assim que todos os jogadores vejam o que está ocorrendo na partida. Porém, as respostas dos comandos são enviadas apenas para o bot autor do comando. Por exemplo, todos receberão uma mensagem de GET_STOCK quando esta for realizada por um bot, mas apenas ele receberá a carta que foi puxada.

...