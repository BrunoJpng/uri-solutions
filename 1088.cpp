#include <iostream>

using namespace std;

int c = 0;

void Merge(int *A, int i, int f)
{
  int m = (i + f) / 2;
  int it1 = i, it2 = m + 1;
  int *aux = (int *)malloc((f - i + 1) * sizeof(int));
  int itaux = 0;

  while (it1 <= m && it2 <= f)
  {
    if (A[it1] < A[it2])
    {
      aux[itaux] = A[it1];
      it1++;
    }
    else
    {
      aux[itaux] = A[it2];
      it2++;
      c += it2 - it1;
    }
    itaux++;
  }

  while (it1 <= m)
  {
    aux[itaux] = A[it1];
    it1++;
    itaux++;
  }
  while (it2 <= f)
  {
    aux[itaux] = A[it2];
    it2++;
    itaux++;
  }

  int a;
  for (a = i; a <= f; a++)
    A[a] = aux[a - i];
}

void MergeSort(int *A, int i, int f)
{
  int m;

  if (i == f)
    return;

  else if (f - i == 1)
  {
    if (A[f] < A[i])
    {
      int aux = A[i];
      A[i] = A[f];
      A[f] = aux;
      c++;
    }
  }
  else
  {
    m = (i + f) / 2;
    MergeSort(A, i, m);
    MergeSort(A, m + 1, f);
    Merge(A, i, f);
  }
}

int main()
{
  int n, p[100005];
  while (true)
  {
    cin >> n;
    if (n == 0)
      break;

    for (int i = 0; i < n; i++)
      cin >> p[i];

    MergeSort(p, 0, n - 1);

    if (c % 2 != 0)
      cout << "Marcelo" << endl;
    else
      cout << "Carlos" << endl;

    c = 0;
  }
  return 0;
}