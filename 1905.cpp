#include <iostream>

using namespace std;

int ganhou = 0;

void FloodFill(int **matriz, int **aux, int x, int y) {
  if (x >= 0 && x < 5 && y >= 0 && y < 5 && !ganhou) {
    aux[x][y] = 1;

    if (x == 4 && y == 4)
      ganhou = 1;
    else {
    if (x > 0 && matriz[x-1][y] == 0 && aux[x-1][y] == 0)
      FloodFill(matriz,aux,x-1,y);
    
    if (y < 4 && matriz[x][y+1] == 0 && aux[x][y+1] == 0)
      FloodFill(matriz,aux,x,y+1);

    if (x < 4 && matriz[x+1][y] == 0 && aux[x+1][y] == 0)
      FloodFill(matriz,aux,x+1,y);
    
    if (y > 0 && matriz[x][y-1] == 0 && aux[x][y-1] == 0)
      FloodFill(matriz,aux,x,y-1);
    }
  }
      
}

int main() {
  int T;
  cin >> T;

  while(T--) {
    int **matriz = (int**)malloc(5*sizeof(int));
    int **visitados = (int**)malloc(5*sizeof(int));

    for(int i=0; i<5; i++) {
      matriz[i] = (int*)malloc(5*sizeof(int));
      visitados[i] = (int*)malloc(5*sizeof(int));
    }

    for(int i=0; i<5; i++)
      for(int j=0; j<5; j++) {
        cin >> matriz[i][j];
        visitados[i][j] = 0;
      }

    ganhou = 0;
    
    FloodFill(matriz, visitados, 0, 0);
    
    if (ganhou) 
      cout << "COPS" << endl;
    else 
      cout << "ROBBERS" << endl;
  }

  return 0;
}