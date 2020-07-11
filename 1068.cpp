#include <stdio.h>
#include <string.h>

int main() {
  char a[1000]; int i = 0;
  while(scanf("%s", a) != EOF || i == 10000){
    int cont1 = 0, cont2 = 0;
  
    for(int i = 0; i < (int) strlen(a); i++){
      if(a[i] == '(') cont1++;
      else if(a[i] == ')') cont2++;
      
      if(cont2 > cont1) break;
    }
    
    if(cont1 == cont2) printf("%s\n", "correct");
    else printf("%s\n", "incorrect");

    i++;
    }
  return 0;
}
