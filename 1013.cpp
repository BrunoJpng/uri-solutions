#include <iostream>

using namespace std;

int main()
{
  int a, b, c;
  cin >> a >> b >> c;

  int maiorAB = (a + b + abs(a - b)) / 2;
  maiorAB = (maiorAB + c + abs(maiorAB - c)) / 2;

  cout << maiorAB << " eh o maior" << endl;

  return 0;
}