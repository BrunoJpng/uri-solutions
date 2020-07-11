#include <iostream>

using namespace std;

int cmp(const void* a, const void* b){
    return(abs(*(int*)a) - abs(*(int*)b));
}
int main(){
    int p,n;
    
    cin >> p;
    
    for(int i=0; i<p; i++){
        cin >> n;
        int edificio[n], cont = 0, ant = 0;
    
        for(int j=0; j<n; j++){
            cin >> edificio[j];
        }
    
        qsort(edificio,n,sizeof(int),cmp);
    
        for(int j=0; j<n; j++){
            if((edificio[j] > 0 && ant <= 0) || (edificio[j] < 0 && ant >= 0)) {
                cont++;
                ant = edificio[j];
            }
        }
        cout << cont << "\n";
    }
    return 0;
}