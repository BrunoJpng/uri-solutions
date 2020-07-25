#include <iostream>

using namespace std;

void print(int *a, int n)
{
  for (int i = 0; i < n; i++)
    cout << a[i] << " ";
  cout << endl;
}

int main()
{
  int n;

  while (true)
  {
    cin >> n;
    if (n <= 0)
      break;

    int remaining[100];
    for (int i = 0; i < n; i++)
      remaining[i] = i + 1;

    int i = 0;
    int size = n;

    cout << "Discarded cards: ";
    while (size > 1)
    {
      if (size != 2)
        cout << remaining[i] << ", ";
      else
        cout << remaining[i] << endl;

      i++;
      size--;
      remaining[n++] = remaining[i];
      i++;
    }
    cout << "Remaining card: " << remaining[i] << endl;
  }
  return 0;
}