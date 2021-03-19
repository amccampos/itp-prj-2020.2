# Projeto da disciplina de ITP - 2020.2

O projeto da disciplina de ITP deste semestre consiste em você desenvolver uma bot para jogar um jogo clássico de cartas: **Buraco**.
Para quem nunca jogou, pode-se experimentar em sites de jogos online, como https://buracoon.com.br/game ou jogar contra o nosso bot do projeto (apresentado mais pra frente).

De qualquer forma, é importante consultar as [regras adotadas nojogo do projeto](./rules.md).

# Funcionamento do jogo

Buraco é um jogo onde duas duplas competem entre si. Ou seja é um jogo tanto competitivo quanto cooperativo (entre os integrantes da dupla). Portanto, normalmente se joga com 4 jogadores, mas pode-se também jogar apenas com 2 jogadores, numa versão *player vs. player*, e é dessa forma que iremos considerar no projeto. Seu bot jogará, portanto, contra outro bot.

No computador, cada bot será um processo diferente rodando de foma concorrente. Ambos serão gerenciados por um terceiro processo, que servirá de "juíz", definindo as jogadas válidas, calculando os pontos e dizendo quem ganhou, mas também gerenciando a troca de mensagens entre os processos dos bots.

É o juíz que irá lançar os processos dos bots (executar seus programas) e ficará de intermediário recebendo as ações dos bots em cada turno e repassando as ações válidas (e visíveis) para os outros bots. Essas informações são trocadas via entrada e saída padrão. Ou seja, o juíz irá ler da entrada-padrão e escrever na saída-padrão dos processos conforme as ações no jogo são realizadas. Assim, para o bot ler um dado do jogo (juíz) é necessário usar `scanf()`, `fgets()` ou equivalentes, enquanto para enviar dados para o jogo (juíz), é necessário usar `printf()`. 

# Pontapé inicial

Um códido que serve de exemplo para dar início ao desenvolvimento de um bot encontra-se no arquivo [bot.c](./bot.c). Nesse código, o bot no seu turno irá puxar uma carta da pilha de compra e depois descartar a carta puxada. Cabe a você melhorar sua estragégia de jogo.

Para testá-lo, você deve compilá-lo gerando um executável e, em seguida, executar o programa juiz (`./buraco`) passando o executável gerado como parâmetro. O juiz é um script desenvolvido em Javascript e, portanto, deve ser chamado usando o `nodeJS`. As linhas a seguir dão o pontapé inicial.

```sh
$ gcc bot.c -o bot
$ node juiz.js bot
```

Como apenas um executável foi passado como parâmetro, o juiz irá lançar um processo especial que irá substituir o bot adversário. Esse processo irá interagir com o usuário, permitindo que você jogue contra seu bot e teste suas estratégias.

Caso queira competir com outro bot (ou mesmo fazer com que seu bot compita contra ele mesmo), é necessário passar o nome dos dois executáveis. Nesse caso, não haverá interação com o usuário.

```sh
$ node juiz.js bot1 bot2
```

# Comunicação

## Início da partida

No início da partida, o juíz irá enviar para todos os bots as seguintes informações (uma em cada linha):
- Os identificadores de todos os jogadores (bots) separados por espaço
- O identificador do bot (seu identificador)
- As cartas que o bot tem na mão
- A carta que se encontra no topo da pilha de descarte (lixo).

O bot deverá, portanto, aguardar a leitura de 4 linhas, como no exemplo abaixo.
```
bot1 bot2
bot1
2♥ 8♥ 10♥ Q♦ Q♦ 5♣ 6♠ 7♠ 10♠ K♠ A♠
4♣
```
Nesse exemplo, o `bot1` recebeu na 1ª linha a identificação dos bots participantes da partida (`bot1 bot2`), seguido de uma linha com seu identificador (`bot1`), seguido das 11 cartas de sua mão (`2♥ 8♥ 10♥ Q♦ Q♦ 5♣ 6♠ 7♠ 10♠ K♠ A♠`), seguido da carta que inicia o lixo (`4♣`). Seu adversário (`bot2`) irá receber dados diferentes na 2ª e na 3ª linhas.

## A cada turno

No início de cada turno, o juíz enviará para todos os bots o identificador do bot que está "na vez" e aguardará uma ação desse bot a ser tomada.

A primeira ação deve obrigatoriamente puxar uma carta, que pode ser do deque de compra ou do topo da pilha de descarte. Porém, se for puxar da pilha, o bot terá que formar um jogo com o que está no topo e as cartas que estão na mão. Fazendo o jogo, ele pegará todas as demais cartas do lixo.

Em seguida, o bot poderá baixar um novo jogo, incluir cartas em jogos existentes ou descartar uma carta no lixo. No momento que descartar, termina sua vez e o próximo bot deve realizar suas ações.

Para realizar uma dessas ações o bot deverá enviar para a saída-padrão um dos seguintes comandos:

- `GET_STOCK`
  Puxa uma carta do deque de compra. Depois do comando, o bot deve ler da entrada-padrão a carta que puxou.
  Por exemplo:
  * envia para saída-padrão: `GET_STOCK`
  * lê da entrada-padrão: `Q♣`

- `GET_DISCARD [ c1 c2 ... ]`
  Pega toda a pilha de descarte (lixo).
  Para isso, é necessário fazer um jogo com a carta do topo da pilha.
  `[ c1 c2 ... ]` são as cartas da mão a serem usadas no jogo. Pelo duas cartas da mão devem ser especificadas uma vez que um jogo válido tem no mínimo três cartas.
  Depois do comando, o bot deve ler uma linha com as cartas que se encontravam no lixo e que serão incorparadas a sua mão.
  Por exemplo:
  * envia para saída-padrão: `GET_DISCARD [ 6♠ 7♠ ]`
  * lê da entrada-padrão: `[ K♥ 4♦ 7♣ 9♣ J♣ J♣ 5♠ ]`

- `MELD_NEW [ c1 c2 c3 ... ]`
  Baixa um jogo na mesa.
  `[ c1 c2 c3 ... ]` são as cartas da mão a serem usadas no jogo. Pelo três cartas da mão devem ser especificadas uma vez que um jogo válido tem no mínimo essa quantidade.
  Depois do comando, não há dados para ler da entrada-padrão.

- `MELD_JOIN ind [ c1 ... ]`
  Anexa cartas a um jogo já existente.
  `ind` é o índice do jogo na ordem em que ele foi criado. O primeiro jogo criado pelo bot terá índice 0, o segundo 1 e assim por diante.
  `[ c1 ... ]` são as cartas da mão a serem anexadas no jogo. Deve-se especificar pelo menos uma carta.
  Depois do comando, não há dados para ler da entrada-padrão.

- `DISCARD c`
  Descarta uma carta na pilha de descarte (lixo).
  `c` é a carta da mão que será descartada.
  Depois do comando, não há dados para ler da entrada-padrão.

Todas os comandos executados por um bot são repassados para os demais bots, permitindo assim que todos os jogadores vejam o que está ocorrendo na partida. Porém, as respostas dos comandos são enviadas apenas para o bot autor do comando. Por exemplo, todos receberão uma mensagem de `GET_STOCK` quando esta for realizada por um bot, mas apenas ele receberá a carta que foi puxada.

Assim que um bot enviar o comando para descartar (`DISCARD`), seu turno termina e passa a ser a vez do outro bot jogar.

**ATENÇÃO**: O bot será automaticamente eliminado (perde) e a partida se dará por encerrada em qualquer um dos seguintes casos:
* Caso algum comando seja enviado fora de ordem (por exemplo, caso a primeira ação de um bot não seja `GET_STOCK` ou `GET_DISCARD`);
* Caso o formato do comando não siga o padrão (por exemplo, `MELD_JOIN` sem parãmetro algum);
* Caso a jogada seja inválida (por exemplo, `MELD_NEW [ 4♦ 7♣ 9♣ ]`, que não forma um jogo válido).

## Término da partida

A partida terminará normalmente quando um dos jogadores descartarem todas as suas cartas. Os pontos serão então contabilizados e o vencedor apresentado. Em caso de erro de mensagens, como descrito acima, o jogo também terminará e o bot autor do erro perderá o jogo independentemente da quantidade de pontos.

## Debugar

