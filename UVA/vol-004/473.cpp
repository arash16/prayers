#include <stdio.h>
#include <iostream>
using namespace std;

int X[10240], t, cse,
	memo[10240][128][128],
	memoid[10240][128][128];
int rec(int s, int d, int rem) {
	if (s<0 || d<0) return 0;
	if (rem<=0) return rec(s, d-1, t);
	if (memoid[s][d][rem] == cse)
		return memo[s][d][rem];

	int res = rec(s-1, d, rem);
	if (X[s] <= rem)
		 res = max(res, rec(s-1, d, rem-X[s]) + 1);
	else res = max(res, rec(s, d-1, t));

	memoid[s][d][rem] = cse;
	return memo[s][d][rem] = res;
}


int main() {
	int T, n, m;
	scanf("%d", &T);
	for(cse=1; cse<=T; cse++) {
		scanf("%d%d%d", &n, &t, &m); // 10240 128 128
		for (int s=0; s<n; s++) {
			scanf("%*[, \t\n]%d", X+s);
		}

		printf("%d\n", rec(n-1, m-1, t));
		if (cse<T) putchar('\n');
	}
}
