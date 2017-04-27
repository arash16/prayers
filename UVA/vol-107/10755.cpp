#include <stdio.h>
#include <iostream>
using namespace std;

long long int X[30][30][30], S[30][30][30], x;
int main(){
	int T, A, B, C;
	cin>>T;
	while (T--) {
		cin >> A >> B >> C;
		long long mx = -(1LL<<63);
		for (int i=1; i<=A; i++)
			for (int j=1; j<=B; j++)
				for (int k=1; k<=C; k++) {
					cin >> X[i][j][k];
					if ((x = X[i][j][k]) > mx) 
						mx = x;
					S[i][j][k] = x + S[i-1][j][k] + S[i][j-1][k] - S[i-1][j-1][k];
				}
		if (mx < 0) 
			cout << mx << endl;

		else {
			for (int i1=0; i1<A; i1++)
				for (int j1=0; j1<B; j1++)
					for (int i2=i1+1; i2<=A; i2++)
						for (int j2=j1+1; j2<=B; j2++) {
							long long s = 0;
						
							for (int k=1; k<=C; k++) {
								s += S[i2][j2][k] - S[i1][j2][k] - S[i2][j1][k] + S[i1][j1][k];
								if (s > mx) mx = s;
								if (s < 0) s = 0;
							}
						}
			cout << mx << endl;
		}
		if (T) putchar('\n');
	}
}
