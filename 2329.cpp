#include <stdio.h>
#define MAX 10000

int paes[MAX], n, k, fatias, inicio, final = MAX + 1, meio;
int ver(int t){
	int i, total=0;
	for(i=0; i<k; i++)
		total += paes[i]/t;
	return (total >= n);
}

main(){
	scanf("%d %d", &n, &k);
	for(int i=0; i<k; i++)
		scanf("%d", &paes[i]);
	while(inicio <= final){
		meio = (inicio + final)/2;
		if(ver(meio)){
			inicio = meio + 1;
			fatias = meio;
		}else
			final = meio - 1;
	}
	printf("%d\n", fatias);
}
