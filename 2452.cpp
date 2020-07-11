#include <stdio.h>
#include <queue>

using namespace std;

int main() {
  int F, R, dias = 0, x, res = 0, k = 0;
  queue <int> fi;
  scanf("%d %d", &F, &R);
  int fita[100001]; 

  fita[0] = 1;
  for(int i=1; i<=F; i++) fita[i]=0;

  for(int i=0; i<R; i++){
    scanf("%d", &x);
    fi.push(x);
  }

  x = 0;
  while(!fi.empty()){
    x = fi.front();
    res++;
    fi.pop();
    fita[x] = 1;
    
    if(fita[x-1] == 0 && x-1 > 0) {
      fi.push(x-1);
      k++;
      fita[x-1] = 1;
    }
    if(fita[x+1] == 0 && x+1 <= F) {
      fi.push(x+1);
      k++;
      fita[x+1] = 1; 
      }
 
    if(res == R){
      R = k;
      k = 0;
      dias++;
      res = 0;
    }   
  }
  printf("%d\n", dias-1);
  return 0;
}
