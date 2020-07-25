#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
  int t, v;
  cin >> t >> v;
  int d = v * t;
  cout << fixed << setprecision(3);
  cout << d / 12.0 << endl;
  return 0;
}