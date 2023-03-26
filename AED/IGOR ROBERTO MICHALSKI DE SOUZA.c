#include "myList.h"
#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int valido(char *str) {
  if (str[0] == '\0'  || strcmp("", str) == 0) {
    return 0;
  }
  int i = strtod(str, NULL);
  if (i <= 10 || i > 1000000) {
    return 0;
  }

  return 1;
}

int verNarci(int n) {
  int s = 0;
  int tempo = n;
  int digitos = 0;
  while (tempo > 0) {
    tempo /= 10;
    digitos++;
  }
  tempo = n;
  while (tempo > 0) {
    s += pow(tempo % 10, digitos);
    tempo /= 10;
  }
  return s == n;
}

int main(int argc, char *argv[]) {

  int n = 0;
  int i = 10;
  int k = 0;
  bool logica = true;

  if(argc != 2){
    printf("Erro, invalido!\n");
    return 1;
  }
  if(!valido(argv[1])){
    printf("Valores invalido\n");
    return 1;
  }

  n = strtod(argv[1], NULL);

  inicializa();

  while(i <= n){
    if(verNarci(i)){
      insere(i);
    }
    i++;
  }

  do{
    imprime();
    i = 0;
    printf("Excluir numero? (1 (para sim), 0 (para nao): ");
    scanf("%d", &k);
    if(k == 1){
      printf("Remover qual numero: ");
      scanf("%d", &i);
      if(busca(i)){
        retira(i);
      } else {
        printf("Não encontramos esse valor\n", i);
      }
    }else{
      logica = false;
      }
  }while(logica == true);

  esvazia();


  return 0;
}
