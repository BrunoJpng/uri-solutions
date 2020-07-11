#include<bits/stdc++.h>

using namespace std;
int main() {

  int N;
  string arv;
  scanf("%d", &N);
  
  cin.ignore();
  cin.ignore();

  for(int i = 0; i<N; i++){
    int cont = 0;
    map <string, double> m;
    map <string, double>::iterator it;
    
    while(getline(cin, arv)){
      if(arv.size() == 0) break;
      m[arv]++;
      cont++;
    }

    if(i>0) printf("\n");

    for(it = m.begin(); it != m.end(); it++){
      printf("%s %.4f\n", it -> first.c_str(), 100* it -> second/cont);
    }
  }
  return 0;
}
