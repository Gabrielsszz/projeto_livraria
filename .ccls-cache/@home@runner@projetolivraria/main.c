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

struct lista_ISBN {
  char info;
  struct lista_ISBN *prox;
};

typedef struct lista_ISBN Lista_ISBN;

Lista_ISBN *incializa1(void) { return NULL; }

Lista_ISBN inserir_IBSN(Lista_ISBN *l, char ISBN) {
  Lista_ISBN *novo = (Lista_ISBN *)malloc(sizeof(Lista_ISBN));
  novo->info = ISBN;
  novo->prox = l;
  return *novo;
}

Lista_ISBN *busca(Lista_ISBN *l, char v) {
  Lista_ISBN *p;
  for (p = l; p != NULL; p = p->prox) {
    if (p->info == v) {
      return p;
    }
  }
  return NULL;
}

struct lista_livros {
  Livro livro;
  struct lista_livros *prox;
};
typedef struct lista_livros BookList;

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
  printf("Insira os dados do livro que deseja cadastrar:\n");
  printf("Título do livro: ");
  scanf("%s", l.titulo);
  printf("Autor: ");
  scanf("%s", l.autor);
  printf("Editora: ");
  scanf("%s", l.editora);
  printf("Ano de edição: ");
  scanf("%d", &l.ano_edicao);
  printf("Número de exemplares: ");
  scanf("%d", &l.num_exemplares);
  printf("ISBN: ");
  scanf("%s", l.ISBN);
  for (p = listaliv; p != NULL; p = p->prox) 
  {
    while (strcmp(l.ISBN, p->livro.ISBN) == 0)
      {
        printf("\nISBN já cadastrado, por favor, tente novamente!\n");
        printf("ISBN: ");
        scanf("%s", l.ISBN);
        p = listaliv;
    }
  }

  return l;
}

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
}
/*int buscabinaria(int t,int v,int isbn){
  int inicio = 0;
  int fim = t -1;
  int meio;
  while(inicio <= fim)
  {
    meio = (inicio + fim)/2;

    if (isbn < v[meio])
    {
      fim = meio - 1
    }else (n > v[meio]){
      inicio = meio +1;
    } else return meio;
  }return -1;
}
*/

int main(void) {
  Lista_ISBN *lis;
  lis = incializa1();
  BookList *bl;
  bl = inicializa();
  int opt1,opt2,opt3;
    
  for(; ;)
  {
      printf("Bem vindo a livraria Nexos!\n")  ;
      printf("O que deseja?\n");
      printf("1 - Cadastrar um livro | 2 - Procurar um livro | 3 - Sair do sistema\n");
      scanf("%d",&opt1);
      if(opt1 == 1)
        {
          Livro livro = cadastro(bl);
          bl = insere_ordenado(bl, livro);
        }
      else if(opt1 == 2)
        {
          printf("Deseja procurar o livro desejado através de qual meio?\n");
          printf("1 - Busca por ISBN | 2 - Busca por Editora | 3 - Busca por Autor\n");
          scanf("%d",&opt2);
          if(opt2 == 1)
            {
              
            }
        
      }
    
    
  }
  //bl = insere_ordenado(bl, livro);
  // printf("autor: %s\n", bl->livro.autor);
  // printf("ISBN: %s\n", bl->livro.ISBN);
  imprime(bl);

  // printf("%s",bl->livro.ISBN);

  return 0;
}

// n sei se ta certo kkkkk
//  int main(){
//    int vet[]={1,2,3,7,4,5,8,9};
//    int tam = sizeof(vet)/sizeof(int);
//    printf("%d \n"buscabinaria(tam,vet,5));
//    return 0;
//  }
