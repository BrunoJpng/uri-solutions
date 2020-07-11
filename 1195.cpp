#include <stdio.h>
#include <stdlib.h>

typedef struct no{
  int valor;
  struct no* esq;
  struct no* dir;
}No;

No* raiz;

No* inserir(No* no, int valor){
  if(!no){
    no = (No*) malloc(sizeof(No));
    no -> valor = valor;
    no -> esq = NULL;
    no -> dir = NULL;
  }
  else if(no -> valor > valor) no -> esq = inserir(no -> esq, valor);
  else no -> dir = inserir(no -> dir, valor);

  return no;
}

No* remover(No* no){
  if(!no) return NULL;
  no -> esq = remover(no -> esq);
  no -> dir = remover(no -> dir);
  free(no);
  return NULL;
}

void preOrdem(No* no){
  if(no != NULL){
    printf(" %d", no -> valor);
    preOrdem(no -> esq);
    preOrdem(no -> dir);
  }
}

void emOrdem(No* no){
  if(no != NULL){
    emOrdem(no -> esq);
    printf(" %d", no -> valor);
    emOrdem(no -> dir);
  }
}

void posOrdem(No* no){
  if(no != NULL){
    posOrdem(no -> esq);
    posOrdem(no -> dir);
    printf(" %d", no -> valor);
  }
}

int main() {
  int C, N, v;
  raiz = NULL;
  scanf("%d", &C);
  for(int i=0; i<C; i++){
    scanf("%d", &N);
    for(int j=0; j<N; j++){
      scanf("%d", &v);
      raiz = inserir(raiz, v);
    }
    printf("Case %d:\n", i+1);
    printf("Pre.:");
    preOrdem(raiz);
    printf("\nIn..:");
    emOrdem(raiz);
    printf("\nPost:");
    posOrdem(raiz);
    printf("\n\n");
    raiz = remover(raiz);
  }
  return 0;
}
