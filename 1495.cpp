#include <iostream>

using namespace std;

void printArray(int* a, int n){
    for(int i=0; i<n; i++){
        cout << a[i] << " ";
    }
    cout <<"\n";
}

int cmp(const void* a, const void* b){
    return (*(int*)a - *(int*)b);
}

int main(){
    int N,G;
    
    while(cin >> N >> G){
        int pontos = 0, cont = 0;
        int S, R, derrotas[N];
        
        for(int i=0; i<N; i++){
            cin >> S >> R;
            int x = S-R;
            
            if(x > 0) pontos += 3;
            
            else if(x == 0){
                if(G > 0){
                    G--;
                    pontos += 3;
                }
                else pontos += 1;
            }
            
            else derrotas[cont++] = -x;
        }
    
        qsort(derrotas,cont,sizeof(int),cmp);
        int i=0;

        while(G>0 && i<cont){
            if(G >= derrotas[i]+1){
                G -= derrotas[i]+1;
                pontos += 3;
            }

            else if(G == derrotas[i]){
                pontos += 1;
                G = -1;
            }
            i++;
        }
        
        cout << pontos << endl;
    }
    return 0;
}

