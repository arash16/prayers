#include <cstring>
#include <stdio.h>

int main() {
	int n, w, sz, p[65536];
	while (scanf("%d", &n)==1 && n) {
		memset(p, 0, (sz=1<<n) << 2);
		for (int i=0; i<sz; ++i) {
			scanf("%d", &w);
			for (int j=1; j<sz; j<<=1)
				p[i^j] += w;
		}

		int mxs = 0;
		for (int i=0; i<sz; ++i)
			for (int j=1; j<sz; j<<=1) {
				int sum = p[i] + p[i^j];
				if (sum > mxs) mxs = sum;
			}

		printf("%d\n", mxs);
	}
}
