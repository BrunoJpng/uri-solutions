#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
  double r;
  cin >> r;

  double vol = (4.0 / 3) * 3.14159 * r * r * r;

  cout << fixed << setprecision(3);
  cout << "VOLUME = " << vol << endl;

  return 0;
}