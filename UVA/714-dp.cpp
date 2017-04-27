#include <stdio.h>
#include <iostream>
using namespace std;

#define INF 4611686018427387904
typedef unsigned long long Long;

Long DP[600][600], sum;
int main(){
	int T, n, k, X[600], Pa[600];
	scanf("%d", &T);
	while (T--) {

		sum = 0;
		scanf("%d%d", &n, &k);

		for (int i=0; i<n; i++) {
			scanf("%d", X+i);
			DP[1][i+1] = (sum += X[i]);
			Pa[i]=-1;
		}


		for (int s=2; s<=k; s++)
			for (int b=s; b<=n; b++) {
				sum = 0;
				DP[s][b] = INF;
				for (int i=1; i<=b-s+1; i++) {
					sum += X[b-i];
					DP[s][b] = min(DP[s][b], max(sum, DP[s-1][b-i]));
				}
			}

		int l=k; sum = 0;
		for (int i=n-1; i>=0; i--) {
			sum += X[i];
			if (sum>DP[k][n] || i+1<l) {
				Pa[--l] = i+1;
				sum = X[i];
			}
		}



		printf("%d", X[0]); l=1;
		for (int i=1; i<n; i++) {
			if (Pa[l] == i) {
				printf(" /");
				l++;
			}
			printf(" %d", X[i]);
		}
		putchar('\n');
	}
}
