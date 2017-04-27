#include <stdio.h>
#include <iostream>
using namespace std;

int G[400][400], G2[400];
int dp(int g[], int n) {
	if (n <= 1) return g[0];
	int d2 = g[0], d1 = max(d2, g[1]);
	for (int i=2; i<n; i++) {
		int d3 = max(d1, d2 + g[i]);
		d2 = d1; // d1=DP[i-1]   d2=DP[i-2]
		d1 = d3;
	}
	return d1;
}

int main() {
	int n, m;
	while (scanf("%d%d", &n, &m)==2) {
		for (int i=0; i<n; i++)
			for (int j=0; j<m; j++)
				scanf("%d", &G[j][i]);
		
		for (int j=0; j<m; j++)
			G2[j] = dp(G[j], n);

		printf ("%d\n", dp(G2, m));
	}
}
