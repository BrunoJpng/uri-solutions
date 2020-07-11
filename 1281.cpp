#include <stdio.h>
#include <string.h>

struct produtos{
  char nome[100];
  float valor;
};

int main() {
  
  int N, M, P, Q;
  float total;
  char f[50];
  scanf("%d", &N);
  
  for(int i=0; i<N; i++){
    total = 0;
    scanf("%d", &M);
    struct produtos lista[M];

    for(int j=0; j<M; j++) scanf("%s %f", lista[j].nome, &lista[j].valor);
    
    scanf("%d", &P);
    
    for(int j=0; j<P; j++){
      scanf("%s %d", f, &Q);
      
      for(int k=0; k<M; k++){
        if(!strcmp(lista[k].nome, f)){
          total += Q*lista[k].valor;
          break;
        }
      }
    }
    printf("R$ %.2f\n", total);
  }
  return 0;
}
