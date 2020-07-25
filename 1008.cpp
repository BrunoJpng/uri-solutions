#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
  int n, h;
  float v;

  cin >> n >> h >> v;
  cout << "NUMBER = " << n << endl;
  cout << fixed << setprecision(2);
  cout << "SALARY = U$ " << h * v << endl;
  return 0;
}