#include <stdio.h>

int main() {
	int n, m, s, e, r;
	while (scanf("%d%d", &n, &m)==2 && (n||m)) {
		bool bits[1000017]={}, conf=0;
		for (int i=0; i<n; ++i) {
			scanf("%d%d", &s, &e);
			if (!conf)
			for (int j=s; j<e; ++j)
				if (bits[j]) { conf=1; break; }
				else bits[j] = 1;
		}

		for (int i=0; i<m; ++i) {
			scanf("%d%d%d", &s, &e, &r);
			for (int k=0; !conf && k<1000001; k+=r) {
				int last = k+e < 1000001 ? k+e : 1000001;
				for (int j=k+s; j<last; ++j)
					if (bits[j]) { conf=1; break; }
					else bits[j] = 1;
			}
		}

		puts(conf ? "CONFLICT" : "NO CONFLICT");
	}
}
