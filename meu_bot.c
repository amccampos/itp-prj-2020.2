/********************************************************************
  Bot-exemplo
  
  Após receber as informações iniciais do jogo, a cada rodada, esse
  bot irá apenas puxar uma carta e, em seguida, descartá-la.
  Cabe a você agora aprimorar sua estratégia!!!
 ********************************************************************/

#include <stdio.h>
#include <string.h>

/** Tamanho máximo de uma linha da entrada-padrão */
#define MAX_LINE 200

/** Tamanho máximo do identificador do bot */
#define ID_SIZE 20

typedef struct cartas{
  int numero;
  char naipe[5];
} Carta;

//  Lê uma linha da entrada padrão e remove o '\n' se necessário.
void readline(char *line) {
  fgets(line, MAX_LINE, stdin);
  int l = strlen(line) - 1;
  if(line[l] == '\n') {
    line[l] = '\0';
  }
}

int main() {
  char line[MAX_LINE];   // dados temporários
  char myId[ID_SIZE];    // identificador do bot

  FILE* saida = fopen("saida", "w");

  // stdin, stdout e stderr não terão buffers, assim, nada é "guardado temporariamente"
  setbuf(stdin, NULL);   
  setbuf(stdout, NULL); 
  setbuf(stderr, NULL);
  setbuf(saida,NULL);

  int i;
  int indexCopas = 0, indexOuro = 0, indexPaus = 0, indexEspadas = 0;

  char valor;
  char lixo = NULL;
  char naipeAtual[5];
  char *cartas;
  Carta *mao;

  Carta *maoCopas;
  Carta *maoOuro;
  Carta *maoPaus;
  Carta *maoEspadas;

  mao = malloc(sizeof(Carta) * 11);

  maoCopas = malloc(sizeof(Carta) * 11);
  maoOuro = malloc(sizeof(Carta) * 11);
  maoPaus = malloc(sizeof(Carta) * 11);
  maoEspadas = malloc(sizeof(Carta) * 11);

  // DADOS DO INÍCIO DA PARTIDA


  // lê os identificadores dos jogadores (descartavel)
  readline(line);    
  fprintf(saida, "Indentificadores de todos bots: %s\n", line); 
  // lê o identificador do bot (seu id)
  readline(line);        
  fprintf(saida, "Identificador do meu bot: %s ", line);
  //Armazena o id do bot que foi lido anteriormente
  strncpy(myId, line, ID_SIZE);
  fprintf(saida, "myID: %s\n", myId);



  //Guardar as cartas iniciais aqui
  readline(line); 

  fprintf(saida, "Cartas iniciais: %s\n", line);
  //Leitura das cartas e armazenamento
  cartas = strtok(line, " ");
  // fprintf(saida, "Carta atual: %s\n", cartas);
  cartas = strtok(NULL, " ");
  // fprintf(saida, "Carta atual: %s\n", cartas);

  //Recebndo os números da mão
  for (i = 0; i < 11; i++){
    //Recebe o valor da carta
    sscanf(cartas, "%c", &valor);

    //Se o valor for o caractere 1 (ou seja, é o numero 10)
    if (valor == '1')
    {
      //Recebe o valor (1), um lixo (0), e o naipeAtual
      sscanf(cartas, "%c %c %s", &valor, &lixo, naipeAtual);
    }
    else{
       //Recebe somente o valor e o naipeAtual
       sscanf(cartas, "%c %s", &valor, naipeAtual);
    }

    //Colocando o valor recebido
    if(valor == '1')
    {
      mao[i].numero = 10;
    }
    else if (valor == 'A')
    {
      mao[i].numero = 1;
    }
    else if(valor == 'J')
    {
      mao[i].numero = 11;
    }
    else if(valor == 'Q')
    {
      mao[i].numero = 12;
    }
    else if(valor == 'K')
    {
      mao[i].numero = 13;
    }
    else{
      mao[i].numero = valor - '0';
    }

    //Colocando o naipe recebido na carta
    strcpy(mao[i].naipe, naipeAtual);

    //Separação da mão em naipes
    if((strcmp(naipeAtual, "♥") == 0))
    {
      strcpy(maoCopas[indexCopas].naipe, naipeAtual);
      maoCopas[indexCopas].numero = mao[i].numero;
      indexCopas++;
    }
    if((strcmp(naipeAtual, "♦") == 0))
    {
      strcpy(maoOuro[indexOuro].naipe, naipeAtual);
      maoOuro[indexOuro].numero = mao[i].numero;
      indexOuro++;
    }
    if((strcmp(naipeAtual, "♠") == 0))
    {
      strcpy(maoEspadas[indexEspadas].naipe, naipeAtual);
      maoEspadas[indexEspadas].numero = mao[i].numero;
      indexEspadas++;
    }
    if((strcmp(naipeAtual, "♣") == 0))
    {
      strcpy(maoPaus[indexPaus].naipe, naipeAtual);
      maoPaus[indexPaus].numero = mao[i].numero;
      indexPaus++;
    }

    //Printa a carta atual
    fprintf(saida, "Carta[%d]: %d%s\n", i, mao[i].numero, mao[i].naipe);

    cartas = strtok(NULL, " ");
  }

  //print da mao dividida
  //Print Mão Copas
  fprintf(saida, "Mao copas: [ ");
  for (i = 0; i < indexCopas; i++){
  fprintf(saida, "%d%s ", maoCopas[i].numero, maoCopas[i].naipe);
  }
  fprintf(saida, "]\n");
  //Print Mão Ouro
  fprintf(saida, "Mao ouro: [ ");
  for (i = 0; i < indexOuro; i++)
  {
  fprintf(saida, "%d%s ", maoOuro[i].numero, maoOuro[i].naipe);
  }
  fprintf(saida, "]\n");
  //Print Mão Espadas
  fprintf(saida, "Mao espadas: [ ");
  for(i = 0; i < indexEspadas; i++)
  {
  fprintf(saida, "%d%s ", maoEspadas[i].numero, maoEspadas[i].naipe);
  }
  fprintf(saida, "]\n");
  //Print Mão Paus
  fprintf(saida, "Mao Paus: [ ");
  for(i = 0; i < indexPaus; i++)
  {
  fprintf(saida, "%d%s ", maoPaus[i].numero, maoPaus[i].naipe);
  }
  fprintf(saida, "]\n");

  //gcc meu_bot.c -o meu_bot -g -w
  //node buraco.js meu_bot bot
  //node buraco -i test_files/ex1.txt bot

//Inicializar o lixo e ler a carta lida
  readline(line);        // lê a carta inicial da pilha de descarte.

  
  //Loop infinito gerenciado pelo juiz
  while(1) {              // DADOS DURANTE A PARTIDA
    do {                  // lê e descarta os dados até chegar sua vez


      readline(line);     // sai do laço quando for enviado seu id


      fprintf(stderr, "%s\n", line);  // exemplo de saída para debugar

      //Verificar se o adversario deu o comando discard para atualizar o lixo

      //Verificar se o adversario deu o comando GET_DISCARD, neste caso é necessario zerar o lixo

    } while (strcmp(line, myId)); // sai do laço quando for a sua vez!


    printf("GET_STOCK\n");         // envia a ação para puxar uma carta
    readline(line);                // recebe a carta que puxou
    printf("DISCARD %s\n", line);  // descarta a carta que puxou
  }

  return 0;
}


//Dicas
//4 vetores para cada naipe
//Ordenar os 4 vetores de forma crescente

//Verificações do A e do 2 a parte na hora de montar jogos