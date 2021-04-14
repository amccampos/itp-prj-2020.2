//gcc meu_bot.c -o meu_bot -g -w
//node buraco.js meu_bot bot
//node buraco -i test_files/ex1.txt bot


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/** Tamanho máximo de uma linha da entrada-padrão */
#define MAX_LINE 200

/** Tamanho máximo do identificador do bot */
#define ID_SIZE 20

int indexCopas = 0, indexOuro = 0, indexPaus = 0,indexEspadas = 0;

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

void bubblesortNaipes(Carta *mao, int index)
{
  Carta aux;

  for (int i = 0; i < index - 1; i++)
    {
        for (int k = i + 1; k < index; k++)
        {
            //Ordenação por pontos
            if (mao[i].numero > mao[k].numero)
            {
              aux = mao[i];
              mao[i] = mao[k];
              mao[k] = aux;
                
            }
        }
    }
}

char* puxar(){
  return "GET_STOCK";
}

void valorCarta(char* carta, Carta* mao){
  char valor;
  char lixoBuffer;
  char naipeAtual[5];

  sscanf(carta, "%c", &valor);

  if (valor == '1')
    {
      //Recebe o valor (1), um lixoBuffer (0), e o naipeAtual
      sscanf(carta, "%c %c %s", &valor, &lixoBuffer, naipeAtual);
    }
    else{
       //Recebe somente o valor e o naipeAtual
       sscanf(carta, "%c %s", &valor, naipeAtual);
    }

     //Colocando o valor recebido
    if(valor == '1')
    {
      mao->numero = 10;
    }
    else if (valor == 'A')
    {
     mao->numero = 1;
    }
    else if(valor == 'J')
    {
     mao->numero = 11;
    }
    else if(valor == 'Q')
    {
     mao->numero = 12;
    }
    else if(valor == 'K')
    {
     mao->numero = 13;
    }
    else{
     mao->numero = valor - '0';
    }

    strcpy(mao->naipe, naipeAtual);
}

void tratamentoNaipe(Carta* mao, Carta* maoCopas, Carta* maoOuro, Carta* maoEspadas, Carta* maoPaus)
{
  FILE* tratamento = fopen("tratamento", "w");
  fprintf(tratamento,"oi");

  if((strcmp(mao->naipe, "♥") == 0))
  {
    strcpy(maoCopas[indexCopas].naipe, mao->naipe);
    maoCopas[indexCopas].numero = mao->numero;
    indexCopas++;
    // maoCopas = realloc(maoCopas, sizeof(Carta*) *(indexCopas + 1));
  }
  if((strcmp(mao->naipe, "♦") == 0))
  {
    strcpy(maoOuro[indexOuro].naipe, mao->naipe);
    maoOuro[indexOuro].numero = mao->numero;
    indexOuro++;
    // maoOuro = realloc(maoOuro, sizeof(Carta) *(indexOuro + 1));
  }
  if((strcmp(mao->naipe, "♠") == 0))
  {
    strcpy(maoEspadas[indexEspadas].naipe, mao->naipe);
    maoEspadas[indexEspadas].numero = mao->numero;
    indexEspadas++;
    // maoEspadas = realloc(maoEspadas, sizeof(Carta) *(indexEspadas + 1));
  }
  if((strcmp(mao->naipe, "♣") == 0))
  {
    strcpy(maoPaus[indexPaus].naipe, mao->naipe);
    maoPaus[indexPaus].numero = mao->numero;
    indexPaus++;
    // maoPaus = realloc(maoPaus, sizeof(Carta) *(indexPaus + 1));
  }
}

void printMaoNaipes(Carta* mao, Carta* maoCopas, Carta* maoOuro, Carta* maoEspadas, Carta* maoPaus, FILE* saida)
{
  int i = 0;
    //Print Mão Copas
    fprintf(saida, "Mao copas: [ ");
    for (i = 0; i < indexCopas; i++){
    fprintf(saida, "%d%s ", maoCopas[i].numero, maoCopas[i].naipe);
    }
    fprintf(saida, "] index: %d\n", indexCopas);


    //Print Mão Ouro
    fprintf(saida, "Mao ouro: [ ");
    for (i = 0; i < indexOuro; i++)
    {
    fprintf(saida, "%d%s ", maoOuro[i].numero, maoOuro[i].naipe);
    }
    fprintf(saida, "] index: %d\n", indexOuro);


    //Print Mão Espadas
    fprintf(saida, "Mao espadas: [ ");
    for(i = 0; i < indexEspadas; i++)
    {
    fprintf(saida, "%d%s ", maoEspadas[i].numero, maoEspadas[i].naipe);
    }
    fprintf(saida, "] index: %d\n", indexEspadas);


    //Print Mão Paus
    fprintf(saida, "Mao Paus: [ ");
    for(i = 0; i < indexPaus; i++)
    {
    fprintf(saida, "%d%s ", maoPaus[i].numero, maoPaus[i].naipe);
    }
    fprintf(saida, "] index: %d\n", indexPaus);
}

int main() {
  char line[MAX_LINE];   // dados temporários
  char myId[ID_SIZE];    // identificador do bot

  FILE* saida = fopen("saida", "w");

  //Stdin, stdout e stderr não terão buffers, assim, nada é "guardado temporariamente"
    setbuf(stdin, NULL);   
    setbuf(stdout, NULL); 
    setbuf(stderr, NULL);
    setbuf(saida,NULL);
  //


  int i;
  int indexLixo = 0;


  char valor;
  char lixoBuffer;
  char naipeAtual[5];
  char loop[MAX_LINE];
  char *descarte;
  char *cartas;
  

  
  Carta *mao;
  Carta *maoCopas;
  Carta *maoOuro;
  Carta *maoPaus;
  Carta *maoEspadas;

  Carta *lixo;

  mao = malloc(sizeof(Carta) * 11);
  maoCopas = malloc(sizeof(Carta) * 14);
  maoOuro = malloc(sizeof(Carta) * 14);
  maoEspadas = malloc(sizeof(Carta) * 14);
  maoPaus = malloc(sizeof(Carta) * 14);

  lixo = malloc(sizeof(Carta) * 2);


  // DADOS DO INÍCIO DA PARTIDA

  //Leituras iniciais: Identificadores de todos bots | Identificador do bot 
    // lê os identificadores dos jogadores (descartavel)
    readline(line);    
    fprintf(saida, "Indentificadores de todos bots: %s\n",  line); 
    // lê o identificador do bot (seu id)
    readline(line);        
    fprintf(saida, "Identificador do meu bot: %s ", line);
    //Armazena o id do bot que foi lido anteriormente
    strncpy(myId, line, ID_SIZE);
    fprintf(saida, "myID: %s\n", myId);

  //


  //Guardar as cartas iniciais
  readline(line); 
  fprintf(saida, "Cartas iniciais: %s\n", line);

  //Leitura das cartas separadamente e armazenamento
  cartas = strtok(line, " ");
  cartas = strtok(NULL, " ");


  //Recebendo os números da mão inicial | Separação da mão em naipes
    for (i = 0; i < 11; i++){

    //Colocando o valor da carta
    valorCarta(cartas, &mao[i]);

    //Separação da mão em naipes
    tratamentoNaipe(&mao[i], maoCopas, maoOuro, maoEspadas, maoPaus);
    
    //Printa a carta atual
    fprintf(saida, "Carta[%d]: %d%s\n", i, mao[i].numero, mao[i].naipe);

    cartas = strtok(NULL, " ");
    }
    fprintf(saida, "\n");
  //
  

  //Libera a mão inicial
  free(mao);


  //Ordenação das mãos iniciais de cada naipe
    bubblesortNaipes(maoCopas, indexCopas);
    bubblesortNaipes(maoOuro, indexOuro);
    bubblesortNaipes(maoEspadas, indexEspadas);
    bubblesortNaipes(maoPaus, indexPaus);
  
  //


  //Print da mao dividida em naipes
    printMaoNaipes(&mao[i], maoCopas, maoOuro, maoEspadas, maoPaus, saida);
  //


  //Lê a carta inicial da pilha de descarte.
  readline(line);  
  
  fprintf(saida, "\n");
  fprintf(saida, "\n");

  //Definição da carta inicial do lixo
    fprintf(saida,"lixo: %s\n", line); 

    //Definição do lixo
    valorCarta(line, &lixo[indexLixo]);
    
  //
  

  //Print carta do lixo
  fprintf(saida, "Carta do lixo: %d%s\n", lixo[indexLixo].numero, lixo[indexLixo].naipe);

  indexLixo++;

  fprintf(saida, "\n");
  fprintf(saida, "\n");

  //Loop infinito gerenciado pelo juiz
  while(1) {              // DADOS DURANTE A PARTIDA
    do {                  // lê e descarta os dados até chegar sua vez

      // sai do laço quando for enviado seu id
      readline(line);     

      // exemplo de saída para debugar
      // fprintf(saida, "Loop: %s", line);  

      //Verificar se o adversario deu o comando discard para atualizar o lixo
      sscanf(line, "%s", loop);
      // fprintf(saida,"variavel loop: %s\n", loop);

      if(strcmp(loop, "DISCARD") == 0)
      {
        descarte = strtok(line, " ");
        descarte = strtok(NULL, " ");
        fprintf(saida, "Descarte: %s\n", descarte);
        valorCarta(descarte, &lixo[indexLixo]);
        fprintf(saida, "Topo do lixo: %d%s\n", lixo[indexLixo].numero, lixo[indexLixo].naipe);
        indexLixo++;
        // lixo = realloc(lixo, sizeof(Carta *) * (indexLixo + 1));
      }


      //Verificar se o adversario deu o comando GET_DISCARD, neste caso é necessario zerar o lixo


    } while (strcmp(line, myId)); // sai do laço quando for a sua vez!

    //Envia a ação para puxar uma carta
    for (i = 0; i < indexLixo; i++)
    {
      fprintf(saida, "%d%s ", lixo[i].numero, lixo[i].naipe);
    }
    fprintf(saida, "\n");

    //Tratamento de qual puxe quer fazer
    char* acaoPuxar = puxar();
    // fprintf(saida, "acao puxar: %s\n", acaoPuxar);
    printf("%s\n", acaoPuxar);


    //Recebe a carta que puxou
    readline(line);
    fprintf(saida, "Carta do deque de compra: %s\n", line);

    //Recebimento da carta para a mão geral
    valorCarta(line, &mao[0]);
    fprintf(saida, "Carta recebida: %d%s\n", mao[0].numero, mao[0].naipe); 

    //Separação da carta recebida para o naipe correspondente
    tratamentoNaipe(&mao[0], maoCopas, maoOuro, maoEspadas, maoPaus);

    //Ordenação das mãos de cada naipe
      bubblesortNaipes(maoCopas, indexCopas);
      bubblesortNaipes(maoOuro, indexOuro);
      bubblesortNaipes(maoEspadas, indexEspadas);
      bubblesortNaipes(maoPaus, indexPaus);
    //

    //Print das mãos
    printMaoNaipes(&mao[i], maoCopas, maoOuro, maoEspadas, maoPaus, saida);

    fprintf(saida, "\n");
    fprintf(saida, "\n");

    //Descarta a carta que puxou
    printf("DISCARD %s\n", line);  


  }

  return 0;
}


//Dicas
//4 vetores para cada naipe
//Ordenar os 4 vetores de forma crescente

//Verificações do A e do 2 a parte na hora de montar jogos