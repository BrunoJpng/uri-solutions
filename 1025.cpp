#include <iostream>

using namespace std;

int cmp(const void* a, const void* b){
    return(*(int*) a - *(int*) b);
}

int main(){
    int N,Q, cont = 1;

    while(true){
        cin >> N >> Q;

        if(N == 0 && Q == 0) break;
        
        int m[N], c[Q];
        
        for(int i=0; i<N; i++) cin >> m[i];
        for(int i=0; i<Q; i++) cin >> c[i];
        
        qsort(m,N,sizeof(int),cmp);

        cout << "CASE# " << cont << ":\n";

        for(int i=0; i<Q; i++){
            int indice = -1;
            for(int j=0; j<N; j++){
                if(c[i] == m[j]){
                    indice = j+1;
                    break;
                }
            }
            if(indice == -1) cout << c[i] << " not found\n";
            else cout << c[i] << " found at " << indice << "\n";
        }

        cont++;
    }


    return 0;
}