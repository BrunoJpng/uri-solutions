#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
  int c1, n1, c2, n2;
  double v1, v2, total;

  cin >> c1 >> n1 >> v1 >> c2 >> n2 >> v2;
  total = n1 * v1 + n2 * v2;
  cout << fixed << setprecision(2);
  cout << "VALOR A PAGAR: R$ " << total << endl;

  return 0;
}