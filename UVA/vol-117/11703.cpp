#include <math.h>
#include <stdio.h>

int DP[1000001]={1};
int main() {
	for (int i=1; i<1000001; i++) {
		double s = sin(i);
		DP[i] = (DP[int(i-sqrt(i))] + DP[int(log(i))] + DP[int(i*s*s)]) % 1000000;
	}
	
	for (int n; scanf("%d", &n)==1 && n>=0; )
		printf("%d\n", DP[n]);
}
