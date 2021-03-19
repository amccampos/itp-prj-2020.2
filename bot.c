/********************************************************************
  Bot-exemplo
  
  Após receber as informações iniciais do jogo, a cada rodada, esse
  bot irá apenas puxar uma carta e, em seguida, descartá-la.
  Cabe a você agora aprimorar sua estratégia!!!
 ********************************************************************/

#include <stdio.h>
#include <string.h>

/** Tamanho máximo de uma linha da entrada-padrão */
#define MAX_LINE 100

/** Tamanho máximo do identificador do bot */
#define ID_SIZE 10

/**
 * Lê uma linha da entrada padrão e remove o '\n' se necessário.
 * @param line string a ser alterada com o conteúdo da entrada-padrão.
 */
void readline(char *line) {
  fgets(line, MAX_LINE, stdin);
  int l = strlen(line) - 1;
  if(line[l] == '\n') {
    line[l] = '\0';
  }
}

int main() {
  char line[MAX_LINE];   // dados temporários
  char myId[ID_SIZE];    // identificador do bot em questão

  setbuf(stdin, NULL);   // stdin, stdout e stderr não terão buffers
  setbuf(stdout, NULL);  // assim, nada é "guardado temporariamente"
  setbuf(stderr, NULL);

  readline(line);        // lê os identificadores dos jogadores
  readline(line);        // lê o identificador do bot (seu id)
  strncpy(myId, line, ID_SIZE); // guarda para uso futuro

  while(1) {
    do {                  // lê e descarta os dados até chegar sua vez
      readline(line);     // sai do laço quando for enviado seu id
    } while (strcmp(line, myId)); // ou seja, quando for a sua vez!

    printf("GET_STOCK\n");  // envia a ação para puxar uma carta
    readline(line);         // recebe a carta que puxou

    printf("DISCARD %s\n", line);  // envia a ação para descartar a carta que puxou
  }

  return 0;
}