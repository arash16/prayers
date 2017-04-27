#include <stdio.h>
int T, n, t, p, DP[71][71], DS[71]={1};
int main(){
	for (n=0; n<71; n++) {
		DP[n][0] = 1;
		for (t=1; t<71; t++) {
			DP[n][t] = DS[t];
			DS[t] = DS[t-1] + DP[n][t];
		}
	}

	scanf("%d", &T);
	while (T--) {
		scanf("%d%d%d", &n, &t, &p);
		printf("%d\n", t>=n*p ? DP[n][t-n*p] : 0);
	}
}
