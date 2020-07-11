#include <iostream>
#include <string.h>

using namespace std;

typedef struct{
    char num[200];
} Numero;

int cmp(const void* a, const void* b){
    char* va = (char*)a;
    char* vb = (char*)b;
    return strcmp(va,vb);
}

int main(){
    int N;
    
    while(cin >> N){
        Numero lista[N];
        int cont = 0;
        for(int i=0; i<N; i++) cin >> lista[i].num;

        qsort(lista,N,sizeof(Numero),cmp);
        Numero atual = lista[0];
        
        for(int i=1; i<N; i++){
            for(int j=0; j<strlen(atual.num); j++){
                if(atual.num[0] != lista[i].num[0]) {
                    atual = lista[i];
                    break;
                }
                
                else if(atual.num[j] == lista[i].num[j]) 
                    cont++;
                
                else{
                    atual = lista[i];
                    break;
                }
            }
        }
        cout << cont << endl;
    }
    return 0;
}