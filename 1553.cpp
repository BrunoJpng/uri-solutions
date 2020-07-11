#include <iostream>

using namespace std;

void Counting(int* A, int n, int f, int k){
    int C[k], cont = 0;
    
    for(int i=0; i<k; i++) C[i] = 0;
    for(int i=0; i<n; i++) {
        C[A[i]] += 1;
        if(C[A[i]] == f) cont ++;
    }
    cout << cont << "\n";
}

int main(){
    int N,K,P[1000],cont, maior = 0;

    while(true){
        cin >> N >> K;
        if(N == K && N == 0) break;

        for(int i=0; i<N; i++) {
            cin >> P[i];
            if(P[i] > maior) maior = P[i];            
        }
        Counting(P,N,K,maior+1);
        maior = 0;
    }
    return 0;
}