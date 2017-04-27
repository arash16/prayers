#include <stdio.h>

int main() {
	int T, n, c[8], r[8];
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		int seen[9]={}, mn = 0;
		for (int j=0; j<n; ++j) {
			scanf("%d", c+j);
			++seen[c[j]];
			mn += c[j];
		}

		for (int i=0; i<n; ++i) {
			scanf("%d", r+i);
			if (seen[r[i]]) --seen[r[i]];
			else mn += r[i];
		}

		int mx = 0;
		for (int i=0; i<n; ++i)
			for (int j=0; j<n; ++j)
				mx += c[j] < r[i] ? c[j] : r[i];

		printf("Matty needs at least %d blocks, and can add at most %d extra blocks.\n", mn, mx-mn);
	}
}
