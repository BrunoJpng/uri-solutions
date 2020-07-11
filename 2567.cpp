#include <stdio.h>
#include <math.h>

using namespace std;

int main(){
  int N, aux, total;
  while(scanf("%d", &N) != EOF ){
    if(N == 0) break;
    int a[N];
    total = 0;

    for(int i=0; i<N; i++) scanf("%d", &a[i]);

    for(int i=0; i<N; i++){
      for(int j=i+1; j<N; j++){
        if(a[i] > a[j]){
          aux = a[i];
          a[i] = a[j];
          a[j] = aux;
        }
      }
    }
    
    int i = 0, j = N-1;
    while(j>i) total += a[j--]-a[i++];
    printf("%d\n", total);
  }
  return 0;
}
