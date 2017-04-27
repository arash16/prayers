#include <cstring>
#include <stdio.h>

bool wd[2048];
int cum[2048];
int countWo(int s, int e) {
	if (s+1 >= e) return 0;
	int m = (e+s)>>1;
	return countWo(s, m) + countWo(m, e) + ((cum[e]-cum[m]==0)^(cum[m]-cum[s]==0));
}

int main() {
	int T, n, m, sz, x;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &m);
		memset(wd, 0, sz=1<<n);
		for (int i=0; i<m; ++i) {
			scanf("%d", &x);
			wd[x-1] = 1;
		}

		for (int i=0; i<sz; ++i)
			cum[i+1] = cum[i] + !wd[i];

		printf("%d\n", countWo(0, sz));
	}
}
