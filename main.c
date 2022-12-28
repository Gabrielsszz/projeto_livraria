#include <stdio.h>
struct livro{
  char ISBN[10]; //ISBN n pode ser repetido!
  char titulo[50];
  char autor[50];
  char editora[35];
  char ano_edicao[10];
  int num_exemplares;
};

typedef struct livro Livro;

int main(void) {
  printf("Hello World\n");
  return 0;
}