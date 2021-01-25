#include <iostream>

using namespace std;

int Troco(int *A, int m, int v) {
  int moedas[v+1];
  for(int i=0; i<=v; i++)
    moedas[i] = 0;
  moedas[0] = 2;

  for(int i=0; i<m; i++) {
    if (A[i] <= v) {
      for(int j=v; j>1; j--) {
        if(moedas[j] > 0 && (A[i] + j) <= v && moedas[A[i]+j] == 0)
          moedas[A[i]+j] = 2;
      }
      moedas[A[i]] = 1;
    }
  }

  return moedas[v];
}

int main() {
  int V, M, moeda;
  cin >> V >> M;

  int moedas[M];

  for(int i=0; i<M; i++)
    cin >> moedas[i];

  if (Troco(moedas, M, V))
    cout << "S" << endl;
  else
    cout << "N" << endl;
  
  return 0;
}