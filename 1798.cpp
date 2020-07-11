#include <iostream>
#include <string.h>
#define MAX 2500

using namespace std;

int n;
int comp[MAX], val[MAX];
int mat[MAX][MAX];

int CutRod(int u, int p){
    if(u == n || p == 0) return 0;
    if(p < 0) return -9999;

    if(mat[u][p] == -1)
        mat[u][p] = max(CutRod(u+1,p), val[u] + CutRod(u,p-comp[u]));
    
    return mat[u][p];
}

int main(){
    int t;
    
    while(cin >> n >> t){
        for(int i=0; i<n; i++) cin >> comp[i] >> val[i];
        memset(mat,-1,sizeof(mat));
        
        cout << CutRod(0,t) << endl;
    }
    
    return 0;
}