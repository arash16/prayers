#include <stdio.h>
#include <iostream>
using namespace std;

#define INF 1073741824

int S[20], DP[20][20], P[20][20];

void print(int s, int e) {
	if (e == s+1)
		cout << "A" << e;
	else {
		putchar('(');
		print(s, P[s][e]);
		cout << " x ";
		print(P[s][e], e);
		putchar(')');
	}
}

int main(){
	int cse=1, n;
	while (cin>>n && n) {
		for (int i=0; i<n; i++) {
			cin>>S[i]>>S[i+1];
			DP[i][i+1]=0;
		}
		
		for (int l=2; l<=n; l++) 
			for (int i=0; i<=n-l; i++) {
				int j = i + l;
				DP[i][j] = INF;
				for (int k=1; k<l; k++) {
					int t = DP[i][i+k] + DP[i+k][j] + S[i]*S[i+k]*S[j];
					if (t < DP[i][j]) {
						DP[i][j] = t;
						P[i][j] = i+k;
					}
				}
			}

		printf("Case %d: ", cse++);
		print(0, n);
		putchar('\n');
	}
}
