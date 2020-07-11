#include <stdio.h>
#include <stack>
#include <queue>

using namespace std;

int main() {
  
  int n, x1, x2;
  bool fi, pf, pi;

  while(scanf("%d", &n) != EOF){
    queue<int> fila;
    priority_queue<int> prioritaria;
    stack<int> pilha;
    fi = true, pf = true, pi = true; 
    
    for(int i=0; i<n; i++){
      scanf("%d %d", &x1, &x2);
      if(x1 == 1){
        fila.push(x2);
        prioritaria.push(x2);
        pilha.push(x2);
      } 
      else {
        if(prioritaria.top() != x2) pf = false;
        prioritaria.pop();
        if(fila.front() != x2) fi = false;
        fila.pop();
        if(pilha.top() != x2) pi = false;
        pilha.pop();
      }
    }

    if((fi && pf && pi) || (!fi && pf && pi) || (fi && !pf && pi) || (fi && pf && !pi)) printf("not sure\n");
    else if(fi) printf("queue\n");
    else if(pf) printf("priority queue\n");
    else if(pi) printf("stack\n");
    else printf("impossible\n");
  }
  return 0;
}
