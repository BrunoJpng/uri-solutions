#include <stdio.h>
#include <stdlib.h>
#include <queue>

using namespace std;

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

void bfs(No* no){
  No* v;
  queue <No* > fila;
  printf("%d", no -> valor);
  fila.push(no -> esq);
  fila.push(no -> dir);

  while(!fila.empty()){
    v = fila.front();
    fila.pop();
    if(!v) continue;
    printf(" %d", v -> valor);
    fila.push(v -> esq);
    fila.push(v -> dir);
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
    bfs(raiz);
    printf("\n\n");
    raiz = remover(raiz);
  }
  return 0;
}
