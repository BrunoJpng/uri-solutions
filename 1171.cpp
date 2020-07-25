#include <iostream>
#define MAX 2500

using namespace std;

int main()
{
  int n, x;
  int freq[MAX] = {0};
  cin >> n;

  for (int i = 0; i < n; i++)
  {
    cin >> x;
    freq[x]++;
  }

  for (int i = 0; i < MAX; i++)
    if (freq[i] != 0)
      cout << i << " aparece " << freq[i] << " vez(es)\n";
  return 0;
}