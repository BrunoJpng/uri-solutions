#include <iostream>

using namespace std;

struct Cano {
  int comp;
  int val;
};

int CortandoCanos(Cano *A, int n, int t) {
  int aux[t+1];
  int res = 0;

  for(int i=0; i<=t; i++)
    aux[i] = 0;
  
  for(int i=0; i<n; i++) {
    if (A[i].comp < t)
      aux[A[i].comp] = max(aux[A[i].comp], A[i].val);

    for(int j=0; j<=t; j++) {
      if (aux[j] > 0 && j+A[i].comp <= t) {
        aux[j+A[i].comp] = max(aux[j+A[i].comp], aux[j] + A[i].val);
        res = max(res, aux[j+A[i].comp]);
      }
    }
  }

  return res;
}

int main(){
  int n, t;
  
  while(cin >> n >> t){
    Cano canos[n];
    
    for(int i=0; i<n; i++) 
      cin >> canos[i].comp >> canos[i].val;
      
    cout << CortandoCanos(canos,n,t) << endl;
  }

  
  return 0;
}