# include<stdio.h>
#include<ctype.h>

int main(){
	int n, a, b, x;
	char l;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d%c%d", &a, &l, &b);
		if(a == b){
			x = a*b;
		}else if(l == toupper(l)){
			x = b - a;
		}else{
			x = a + b;
		}
		printf("%d\n", x);
	}
	return 0;
}
