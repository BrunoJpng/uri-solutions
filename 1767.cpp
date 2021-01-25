#include <iostream>

using namespace std;

struct Pacote {
  int qtBrinquedos;
  int qtPacotes;
  int peso;
};

Pacote knapsack(Pacote *S, int n, int W) {
  Pacote m[W+1][n+1];
  int res[3];

  for(int j = 0; j <= n; j++) {
    m[0][j].qtBrinquedos = 0;
    m[0][j].qtPacotes = 0;
  }

  for(int w = 0; w <= W; w++) {
    m[w][0].qtBrinquedos = 0;
    m[w][0].qtPacotes = 0;
  }

  for(int j = 1; j <= n; j++) {
    for(int w = 1; w <= W; w++) {
      if (S[j-1].peso > w)
        m[w][j] = m[w][j-1];
      
      else {
        if (m[w-S[j-1].peso][j-1].qtBrinquedos + S[j-1].qtBrinquedos > m[w][j-1].qtBrinquedos) {
          m[w][j].qtBrinquedos = m[w-S[j-1].peso][j-1].qtBrinquedos + S[j-1].qtBrinquedos;
          m[w][j].qtPacotes = m[w-S[j-1].peso][j-1].qtPacotes + 1;
        } else {
          m[w][j].qtBrinquedos = m[w][j-1].qtBrinquedos;
          m[w][j].qtPacotes = m[w][j-1].qtPacotes;
        }
      }    
      
      if (m[w][j].qtBrinquedos > m[w-1][j].qtBrinquedos && j == n) 
        m[W][n].peso = w;
    }
  }

  return m[W][n];
}

int main() {
  int n, pac;
  cin >> n;

  while(n--) {
    cin >> pac;

    Pacote pacotes[pac];

    for(int i=0; i<pac; i++)
      cin >> pacotes[i].qtBrinquedos >> pacotes[i].peso;

    Pacote res = knapsack(pacotes, pac, 50);

    cout << res.qtBrinquedos << " brinquedos" << endl;
    cout << "Peso: " << res.peso << " kg" << endl;
    cout << "sobra(m) " << pac - res.qtPacotes << " pacote(s)" << endl;
    cout << endl;
  }

  return 0;
}