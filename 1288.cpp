#include <iostream>

using namespace std;

typedef struct {
  int poder;
  int peso;
} Projetil;

int knapsack(Projetil *S, int n, int W) {
  int m[W+1][n+1];

  for(int j = 0; j <= n; j++)
    m[0][j] = 0;

  for(int w = 0; w <= W; w++)
    m[w][0] = 0;

  for(int j = 1; j <= n; j++) {
    for(int w = 1; w <= W; w++) {
      if (S[j-1].peso > w)
        m[w][j] = m[w][j-1];
      
      else
        m[w][j] = max(m[w-S[j-1].peso][j-1] + S[j-1].poder, m[w][j-1]);
    }
  }

  return m[W][n];
}

int main() {
  int casos, N, K, R;
  cin >> casos;

  while(casos--) {
    cin >> N;

    Projetil projeteis[N];

    for(int i=0; i<N; i++)
      cin >> projeteis[i].poder >> projeteis[i].peso;

    cin >> K >> R;

    if (R <= knapsack(projeteis, N, K))
      cout << "Missao completada com sucesso" << endl;
    else
      cout << "Falha na missao" << endl;
  }

  return 0;
}