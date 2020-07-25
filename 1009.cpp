#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
  char nome[20];
  double s, m;

  cin >> nome >> s >> m;
  cout << fixed << setprecision(2);
  cout << "TOTAL = R$ " << s + (m * 0.15) << endl;
  return 0;
}