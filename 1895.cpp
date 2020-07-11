# include <stdio.h>
# include <math.h>

int main(){
	int n, t, l, s, a=0, b=0, x;
	scanf("%d %d %d", &n, &t, &l);
	if(n % 2 != 0){
		for(int i = 0; i < n-1; i++){
			scanf("%d", &s);
			if(fabs(t - s) <= l){
				x = fabs(t - s);
				t = s;
			}
			if(i % 2 == 0 && t == s){
				a += x;
			}else if(i % 2 != 0 && t == s){
				b += x;
			}
		}
		printf("%d %d\n", a, b);	
	}
	return 0;
}
