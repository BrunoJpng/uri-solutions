#include <iostream>

using namespace std;

int maxSumSubArray(int *A, int n) {
  int localMax = 0, globalMax = 0;

  for(int i=0; i<n; i++) {
    localMax = max(A[i], A[i] + localMax);
    globalMax = max(localMax, globalMax);
  }

  return globalMax;
}

int main() {
  int N;

  while(cin >> N) {
    int custoPorDia, receita[N];
    cin >> custoPorDia;

    for(int i=0; i<N; i++) {
      cin >> receita[i];
      receita[i] -= custoPorDia;
    }

    cout << maxSumSubArray(receita, N) << endl;
  }

  return 0;
}