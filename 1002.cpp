#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
  double r, n = 3.14159;
  cin >> r;
  double a = n * r * r;
  cout << "A=" << fixed << setprecision(4) << a << endl;
  return 0;
}