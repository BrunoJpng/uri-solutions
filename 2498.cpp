#include <iostream>

using namespace std;

struct Livro {
  int peso;
  int val;
};

int knapsack(Livro *S, int n, int W) {
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
        m[w][j] = max(m[w-S[j-1].peso][j-1] + S[j-1].val, m[w][j-1]);
    }
  }

  return m[W][n];
}

int main() {
  int N, C, cont = 1;
  while(cin >> N >> C, (N || C)) {
    Livro livros[N];

    for(int i=0; i<N; i++)
      cin >> livros[i].peso >> livros[i].val;

    cout << "Caso " << cont << ": " << knapsack(livros, N, C) << endl;
    cont++;
  }

  return 0;
}