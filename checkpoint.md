## Checkpoints do Projeto
Olá!
Primeiro, vamos esclarecer uma coisa: o checkpoint não é um marco obrigatório, que se você não atingir, fica com zero. Ele é apenas um conjunto de metas para direcionar o seu trabalho, caso você esteja perdido ou desorientado. A ideia é que você tente alcançar o que se espera nos checkpoints, mas se não conseguir, tudo bem, tem como compensar depois.

No projeto, vocês vão criar um bot para jogar buraco. Percebam que a gestão do jogo é feita por um programa terceiro, o juíz em javascript, e que vocês vão implementar “um jogador” da partida. Todas as ações vão ser comunicadas através de troca de mensagens
pela entrada e saída padrão, através dos scanfs, fgets e printfs da vida.

Então o que danado eu preciso implementar para ter um jogador?
Perceba que para o bot conseguir jogar, você vai precisar implementar:
- Os “sentidos” dele: o que ele vê, basicamente
- O “raciocínio básico” dele: que passos ele deve tomar para realizar uma jogada,
mesmo que ruim.
- O “raciocínio desenrolado” dele: que passos ele deve tomar para realizar uma boa
jogada.

Como o estado do jogo vai ser controlado por outro programa, você precisa manter algum estado salvo no seu bot (ou seja, a memória e os olhos dele), para que ele lembre:
- Que cartas ele tem na mão
- Que jogos ele já baixou

Nossos checkpoints vão ser organizados da seguinte forma:

## Checkpoint 01 - organizando os dados no nosso bot
Nesse checkpoint, o danado do bot nem precisa saber jogar direito. O que eu espero que vocês consigam fazer inicialmente é:
- Definição de tipos de dados: vamos trabalhar com cartas que possuem valor e naipe, similar a problemas que já tivemos na disciplina. É muito interessante criar
registros e enumerações para tratar disso
- Definição do conjunto de dados a guardar: é preciso guardar a mão e os jogos que foram baixados. Esses dois dados vão variar bastante ao longo do programa, e é importante usar alocação dinâmica na definição deles.
- Processar a entrada e saída: ler as strings e converter para os dados que precisam ser armazenados. e vice-versa.

## Checkpoint 02 - Colocando o bot para jogar
Nesse checkpoint, vamos fazer nosso bot seguir a sequência do fluxo natural do jogo: pegar uma carta, verificar se tem jogo para baixar e descartar uma carta. Aqui ele não precisa ainda fazer a melhor jogada do mundo, apenas queremos que ele consiga seguir o fluxo do jogo e enviar as mensagens de acordo para o programa juíz. Ou seja, deixar ele funcionando, mesmo que lezin.
- Implementar puxada de carta verificando se dá pra puxar o lixo ou não
- Organizar a mão para verificar se há jogos a serem puxados. Pensar em deixar a mão organizada por naipes (os jogos, tirando os melés, precisam ser de mesmo naipe)
- Implementar a seleção do descarte (qualquer estratégia)

## Checkpoint 03 - Implementar estratégias para deixar o bot mais inteligente
Nessa etapa você já terá um bot funcional, e pode pensar em como implementar estratégias para tentar jogadas melhores, inclusive memorizando informações completas da partida, como as cartas no lixo e os jogos dos adversários. Aqui vai depender do quanto de experiência você tem com o jogo Buraco. Eu não sei quase nada, então nem sugestão eu tenho. Talvez algumas….
- Fazer verificação se é possível trocar um jogo sujo por um limpo (se dá pra substituir um melé por uma carta na mão)
- Descartar a carta que tem menos chance de formar um jogo na mão, ou de ser encaixada nos jogos baixados, tanto seu como do adversário.
- Verificar possibilidade de adição de cartas em jogos para formar canastras Os checkpoints são incrementais. Você não deve avançar para o 02 antes de concluir o que
precisa para o 01, porque ele tem, em tese, a base necessária para a implementação do próximo checkpoint.

### Os principais critérios de avaliação do projeto são:
- Uso de tipos de dados
- Uso de alocação dinâmica
- Organização do código e lógica de programação
- Modularização em funções
- Modularização em arquivos (aqui você pode fazer mais de um arquivo para criar o executável do seu bot, dividindo as funcionalidades. Por exemplo, um arquivo para tratar as funções de entrada e saída, um arquivo para as funções relacionadas à estratégia do jogo, etc…).

Qualquer elemento extra além desses citados (arquivos, recursão, etc…) serão avaliados como pontos extras ao que foi desenvolvido.

Parece grande e assustador, mas quando vocês começarem a desenvolver, vão ver que é mais uma questão de ir resolvendo um probleminha de cada vez. Eu particularmente
recomendo vocês trabalharem no repl.it com a base de código pronta, e ir copiando o bot.c e criando os arquivos ali dentro mesmo. É possível trabalhar com compilação de múltiplos arquivos no repl.it, basta em vez de apertar o botão de compilar, ir para a aba console e
realizar os passos de compilação na mão. Os arquivos normalmente ficam todos na mesma pasta, e é fácil de organizar.

Boa programação!