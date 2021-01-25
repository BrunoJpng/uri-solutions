#include <iostream>

using namespace std;

int calc(int **matriz, int len){
  int cont = 0;

  for (int i = 0; i < len; i++){
    for (int j = 0; j < len; j ++)
      if (matriz[i][j] == 1)
        cont++;
  }

  return cont;
}

int CelulaSegura(char **V, int linha, int coluna, int n) {
  if ((linha == 0 && V[linha][coluna] == 'A') || (linha == n-1 && V[linha][coluna] == 'V'))
    return 0;

  if ((coluna == 0 && V[linha][coluna] == '<') || (coluna == n-1 && V[linha][coluna] == '>'))
    return 0;

  return 1;
}

int BackTracking(char** V, int** A, int linha, int coluna, int n) {
  int retorno = 0;

  if (!CelulaSegura(V,linha,coluna,n)) {
    A[linha][coluna] = 2;
    return 2;
  }

  else if (A[linha][coluna] == 1)
    return 1;

  else if (A[linha][coluna] == 2)
    return 2;

  else {
    if(A[linha][coluna] == 0)
      A[linha][coluna] = 1;

    if (linha+1 < n)
      if(V[linha][coluna] == 'V')
        retorno = BackTracking(V,A,linha+1,coluna,n);
    
    if (linha-1 >= 0)
      if (V[linha][coluna] == 'A')
        retorno = BackTracking(V,A,linha-1,coluna,n);

    if (coluna+1 < n)
      if (V[linha][coluna] == '>')
        retorno = BackTracking(V,A,linha,coluna+1,n);

    if (coluna-1 >= 0)
      if (V[linha][coluna] == '<')
        retorno = BackTracking(V,A,linha,coluna-1,n);

    
    if (retorno == 2) {
      A[linha][coluna] = 2;
      return 2;
    }
  }

  return retorno;  
}

int main() {
  int N, cont = 0;
  cin >> N;

  char **matriz = (char**)malloc(N*sizeof(char*));
  int **aux = (int**)malloc(N*sizeof(int*));

  for(int i=0; i<N; i++) {
    matriz[i] = (char*)malloc(N*sizeof(char));
    aux[i] = (int*)malloc(N*sizeof(int));
  }

  for(int i=0; i<N; i++)
    for(int j=0; j<N; j++) {
      cin >> matriz[i][j];
      aux[i][j] = 0;
    }

  for(int i=0; i<N; i++) {
    for(int j=0; j<N; j++)
      if(aux[i][j] == 0)
        BackTracking(matriz,aux,i,j,N);
  }

  cout << calc(aux,N) << endl;

  return 0;
}