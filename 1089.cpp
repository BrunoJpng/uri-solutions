#include <stdio.h>

int main() {
  while(true){
    int N, picos = 0;
    scanf("%d", &N);
    if(N == 0) break;
    int H[N];

    for(int i = 0; i < N; i++) scanf("%d", &H[i]);
    
    int ant = H[N-1], prox;

    for(int i = 0; i < N; i++){
      if(i == N-1) prox = H[0];
      else prox = H[i+1];

      if((H[i] < ant && H[i] < prox) || (H[i] > ant && H[i] > prox)) picos++;
      ant = H[i];
    }
    printf("%d\n", picos);
  }
  return 0;
}
