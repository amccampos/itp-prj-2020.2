# Regras do Buraco usado no projeto

O jogo de Buraco foi criado na década de 40 no Uruguai e, desde então, foi sofrendo adaptações e alterações. Isso fez com que haja diferentes versões de regras. Existe o Buraco simples, Buraco duro, Buraco com ou sem trincas, com ou sem Joker etc. Devido a essas variações e às simplificações que realizamos para o projeto de ITP, é necessário especificar o que vale ou não vale na versão do projeto.

## Visão geral do jogo

O objetivo do jogo é fazer o máximo de pontos que puder, baixando jogos (sequências de cartas de mesmo naipe) na mesa.

## Preparação

Antes de começar a partida, cada jogador recebe 11 cartas (que não devem ser reveladas), uma é colocada no centro da mesa com a face para cima e o resto das cartas é colocada em pilha com as faces para baixo. As cartas de cada jogador são chamadas de **mão** do jogador (aquelas que só ele conhece). A carta no centro servirá como início das cartas descartadas, ou *lixo*, enquanto as cartas voltadas para baixo servirão para puxar novas cartas, também chamado de  *deque de compra*. Nessa versão do jogo, não teremos *mortos*, mas numa versão normal do Buraco, teríamos 2 outros conjuntos de 11 cartas separados que serviriam para os jogadores que terminarem suas cartas na mão.

## Partida

O jogo começa com um jogador qualquer (no projeto um jogador é escolhido aleatoriamente), que deve realizar a seguinte sequência de ações:

1. **Puxar uma carta**. A carta pode ser puxada do topo do deque de compra ou do lixo. Porém, se for do lixo, é preciso baixar um novo jogo com a carta do topo do lixo e cartas da mão do jogador. Nesse novo jogo, pode ser usado um melé (coringa) para completar uma carta que esteja faltando. Depois que o jogo é baixado, todas as cartas restantes do lixo vão pra mão do jogador. Obs: o topo do lixo não pode ser "encaixado" em jogos já baixados.

2. **Formar jogos**. Depois da carta puxada, o jogador poderá baixar novos jogos ou completar jogos existentes com as cartas da mão. Essa etapa não é obrigatória, visto que nem sempre se tem jogos ou cartas para baixar.

3. **Descartar uma carta**. O jogador deve descartar uma de suas cartas na pilha de descarte (lixo). Ao fazer isso, sua jogada termina e passa a vez ao próximo jogador.

O jogo continua com cada jogador repetindo essas 3 etapas (a segunda é opcional) até que um jogador não tenha mais carta na mão. Quando isso ocorrer, a partida termina (não há *morto* nessa versão) e passa a contagem de pontos. Veja portanto que não ganha quem baixa todas as cartas primeiro, mas quem faz mais pontos com as cartas baixadas.

## Jogos

Jogos são sequências de no mínimo 3 cartas consecutivas do mesmo naipe. Na sequência, o Ás pode ser colocado tanto antes do 2 quando depois do rei (K). Assim, temos a sequinte ordem de cartas: *Ás, 2, 3, 4, 5, 6, 7, 8, 9, 10, J, Q, K e Ás*, onde J é o valete (Jack), Q a rainha (Queen) e K o rei (King).

Qualquer sequência de 3 cartas ou mais do mesmo naipe nessa ordem é considerada um jogo e pode ser baixada. O 2 pode também servir de *coringa* (ou *melé*), substituindo uma carta da sequência que esteja faltando. Nesse caso, o naipe do 2 não importa. Assim, a sequência [ 4♥ 5♥ 2♣ 7♥ ] é um jogo válido. Porém, apenas um melé pode ser usado num jogo. Logo, a sequência  [ 4♥ 5♥ 2♣ 7♥ 2♦ 9♥ ] não é válida.

Quando um jogo é formado por 7 ou mais cartas é chamado de canastra. Para esse projeto, serão consideradas apenas 2 tipos de canastras, cada uma com uma pontuação própria:
* Canastra limpa: sequência de pelo menos 7 cartas sem usar melé (carta 2).
* Canastra suja: sequência de pelo menos 7 cartas, mas com o uso do melé.

Nessa versão do jogo, não é permitido trincas, que são sequência de cartas de mesmo valor e pelo menos 3 naipes diferentes.

## Pontuação

Quando a partida termina, os pontos dos jogadores são contabilizados e ganha quem somar mais pontos. São somados os pontos dos jogos baixados (os que estão na mão do jogador não conta), descontados os pontos das cartas da mão do jogador (ou seja, se tiver muita carta na mão vai ser descontado) e somados pontos para da "batida" (quem tiver descartado todas as cartas primeiro ganha um pouco mais).

Para os pontos dos jogos baixados são somados os valores individuais das cartas mais os pontos de eventuais canastras formadas. As cartas valem os seguintes pontos:
* do 3 ao 7: 5 pontos
* 2 e do 8 ao K: 10 pontos
* Ás: 15 pontos

As canastram valem os seguintes pontos:
* Canastra limpa: 200 pontos.
* Canastra suja: 100 pontos.

O jogador que bater (descartar todas as cartas primeiro) terá um adicional de 100 pontos. O jogador que não bater terá consequente cartas na mão, cuja soma dos pontos (apresentados acima) será deduzida de seus jogos baixados.

## Dicas

Na elaboração das estratégias de seu bot, leve em consideração que pegar o lixo é muito importante. Como só pode pegá-lo formando um jogo, suas cartas podem se acumular e servir de fonte de cartas para muito jogos. Assim, é importante também considerar, quando for descartar, cartas em que o adversário provavelmente não conseguirá formar jogo, para não permitir que o lixo seja pego.
