#include <iostream>

using namespace std;

typedef struct{
    int Id;
    int tempo;
    int v;
} fila;

int heapsize = 0;
int cont = 0;

int pqless(fila a, fila b){
    if (a.tempo < b.tempo) return 1;
    if (a.tempo > b.tempo) return 0;

    return (a.Id < b.Id);
}

void insert(fila* A, int z, int v){
    int i = heapsize++;
    A[i].tempo = z;
    A[i].Id = ++cont;
    A[i].v = v;

    while(i != 0 && !pqless(A[(i-1)/2], A[i])){
        fila tmp = A[i];
        A[i] = A[(i-1)/2];
        A[(i-1)/2] = tmp;
        i = (i-1)/2;
    }
}

void maxHeapify(fila* H, int i){
    int maior = i;
    int e = 2*i+1;
    int d = e+1;

    if(e < heapsize && pqless(H[e], H[maior])) maior = e;
    if(d < heapsize && pqless(H[d], H[maior])) maior = d;
    if(maior != i){
        fila aux = H[maior];
        H[maior] = H[i];
        H[i] = aux;
        maxHeapify(H,maior);
    }
}

int main(){
    int N,M,V,C, tempo = 0, maior = 0;
    
    cin >> N >> M;

    fila cx[N];
    
    for(int i=0; i<N; i++) {
        cin >> V;
        insert(cx, tempo, V);
    }
    for(int j=0; j<M; j++) {
        cin >> C;
        cx[0].tempo += cx[0].v * C;
        maxHeapify(cx, 0);
    }

    for(int i=0; i<N; i++){
        if(cx[i].tempo > maior) maior = cx[i].tempo;
    }

    cout << maior << "\n";
    
    return 0;
}