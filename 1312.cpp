#include <iostream>

using namespace std;
 
int main(){
	int n, bola;

	while(cin >> n, n){
		int matriz[n+1][n+1];
		int m_aux[n+1][n+1];

		for(int i=0; i<=n; i++) {
			for(int j=0; j<=n; j++) {
				matriz[i][j] = 0;
				m_aux[i][j] = 0;
			}
		}

		for(int i=1; i<=n; i++) {
			for(int j=1; j<=i; j++) {
				cin >> bola;

				matriz[i][j] = bola + matriz[i-1][j] + matriz[i-1][j-1];
				if(i > 2)
					matriz[i][j] -= matriz[i-2][j-1];

				m_aux[i][j] = matriz[i][j];
			}
		}

		int res = 0;

		for(int j=1; j<=n; j++) {
			if(j > 1) {
				for(int i=j; i<=n; i++) {
					m_aux[i][j] = m_aux[i-1][j-1] + matriz[i][j] - matriz[i-1][j-1];
				}
			}
			
			int melhor = m_aux[n][j];

			for(int i=n; i>0; i--) {
				if(melhor > m_aux[i][j])
					m_aux[i][j] = melhor;

				else
					melhor = m_aux[i][j];
			}

			res = max(res, melhor);
		}
		
		cout << res << endl;
	}
	return 0;
}