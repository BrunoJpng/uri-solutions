#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

int main()
{
  double x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;

  double d = pow(x2 - x1, 2) + pow(y2 - y1, 2);

  cout << fixed << setprecision(4);
  cout << sqrt(d) << endl;

  return 0;
}