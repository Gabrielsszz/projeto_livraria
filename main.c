#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct livro {
  char ISBN[10]; // ISBN n pode ser repetido!
  char titulo[50];
  char autor[50];
  char editora[35];
  int ano_edicao;
  int num_exemplares;
  struct livro *prox;
};
typedef struct livro Livro;

struct lista_livros {
  Livro livro;
  struct lista_livros *prox;
};
typedef struct lista_livros BookList;


void buscaISBN(BookList *l, char procura[]) {
  BookList *p;
  for (p = l; p != NULL; p = p->prox) {
    if (strcmp(procura,p->livro.ISBN) == 0){
      printf("\nTítulo: %s", p->livro.titulo);
      printf("Autor: %s", p->livro.autor);
      printf("Editora: %s", p->livro.editora);
      printf("Ano de edição: %d", p->livro.ano_edicao);
      printf("\nNúmero de exemplares %d", p->livro.num_exemplares);
      printf("\nISBN: %s\n", p->livro.ISBN);
      return;
    }
  }
   printf("\nO ISBN digitado não está cadastrado\n");
}

void busca_editora(BookList *l, char editora[]) {
  BookList *p;
  for (p = l; p != NULL; p = p->prox) {
    if (strcmp(editora,p->livro.editora) == 0){
      printf("\nTítulo: %s", p->livro.titulo);
      printf("Autor: %s", p->livro.autor);
      printf("Editora: %s", p->livro.editora);
      printf("Ano de edição: %d", p->livro.ano_edicao);
      printf("\nNúmero de exemplares %d", p->livro.num_exemplares);
      printf("\nISBN: %s\n", p->livro.ISBN);
      return;
    }
  }
   printf("\nA editora digitada não está cadastrado\n");
  
}
void busca_autor(BookList *l, char autor[]) {
  BookList *p;
  for (p = l; p != NULL; p = p->prox) {
    if (strcmp(autor,p->livro.autor) == 0){
      printf("\nTítulo: %s", p->livro.titulo);
      printf("Autor: %s", p->livro.autor);
      printf("Editora: %s", p->livro.editora);
      printf("Ano de edição: %d", p->livro.ano_edicao);
      printf("\nNúmero de exemplares %d", p->livro.num_exemplares);
      printf("\nISBN: %s\n", p->livro.ISBN);
      return;
    }    
  } 
  printf("\nO autor digitado não está cadastrado\n");
}

BookList *inicializa(void) { return NULL; }

BookList *inserir_livro(BookList *b, Livro l) {
  BookList *novo = (BookList *)malloc(sizeof(BookList));
  novo->livro = l;
  novo->prox = b;
  return novo;
}

BookList *cria(struct livro v) {
  BookList *p = (BookList *)malloc(sizeof(BookList));
  p->livro = v;
  return p;
}

BookList *insere_ordenado(BookList *l, struct livro v) {
  BookList *novo = cria(v);
  BookList *ant = NULL;
  BookList *p = l;

  while (p != NULL && p->livro.ano_edicao < v.ano_edicao) {
    ant = p;
    p = p->prox;
  }
  if (ant == NULL) {
    novo->prox = l;
    l = novo;
  } else {
    novo->prox = ant->prox;
    ant->prox = novo;
  }
  return l;
}

Livro cadastro(BookList *listaliv) {
  Livro l;
  BookList *p;
  printf("\nInsira os dados do livro que deseja cadastrar:\n");
  printf("\nTítulo do livro: ");
  getchar();
  fgets(l.titulo,50,stdin);
  printf("Autor: ");
  fgets(l.autor,50,stdin);
  printf("Editora: ");
  fgets(l.editora,35,stdin);
  printf("Ano de edição: ");
  scanf("%d", &l.ano_edicao);
  printf("Número de exemplares: ");
  scanf("%d", &l.num_exemplares);
  printf("ISBN: ");
  scanf("%s", l.ISBN);
  for (p = listaliv; p != NULL; p = p->prox) {
    while (strcmp(l.ISBN, p->livro.ISBN) == 0) {
      printf("\nISBN já cadastrado, por favor, tente novamente!\n");
      printf("ISBN: ");
      scanf("%s", l.ISBN);
      p = listaliv;
    }
  }

  return l;
}
/*
void imprime(BookList *livro) {
  BookList *p; // variavel para percorrer a lista
  for (p = livro; p != NULL; p = p->prox) {
    printf("Titulo: %s\n", p->livro.titulo);
    printf("Autor: %s\n", p->livro.autor);
    printf("Editora: %s\n", p->livro.editora);
    printf("Ano de edição: %d\n", p->livro.ano_edicao);
    printf("Número de exemplares %d\n", p->livro.num_exemplares);
    printf("ISBN: %s\n", p->livro.ISBN);
  }
}*/

int main(void) {
  BookList *bl;
  bl = inicializa();
  int opt1, opt2, opt3;
  char busca_isbn[10];
  char editora[35];
  char autor[50];

  for (;;) {
    printf("--------------------#-------------------\n");
    printf("Bem vindo a livraria Nexos!\n");
    printf("O que deseja?\n");
    printf("\n1 - Cadastrar um livro | 2 - Procurar um livro | 3 - Sair do sistema\n");
    scanf("%d", &opt1);
    if (opt1 == 1) {
      Livro livro = cadastro(bl);
      bl = insere_ordenado(bl, livro);
      printf("Livro cadastrado com sucesso!\n");
      
    } else if (opt1 == 2) {
      printf("\nDeseja procurar o livro desejado através de qual meio?\n");
      printf(
          "\n1 - Busca por ISBN | 2 - Busca por Editora | 3 - Busca por Autor\n");
      scanf("%d", &opt2);
      if (opt2 == 1) {
        printf("Qual o ISBN do livro que procura?\n");
        scanf("%s",busca_isbn);
        buscaISBN(bl, busca_isbn);
      }
      else if(opt2 == 2){
        printf("Deseja ver os livro de qual editora?\n");
        getchar();
        fgets(editora,35,stdin);
        busca_editora(bl,editora);
      }
      else if(opt2 == 3){
        printf("Deseja buscar os livros de qual autor?\n");
        getchar();
        fgets(autor, 50,stdin);
        busca_autor(bl, autor);
      }

    }else if (opt1 == 3) {
      printf("\nSaindo do sistema...\n");
      break; // encerra o loop infinito
    }
  }

  return 0;
}

