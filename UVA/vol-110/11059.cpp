#include <stdio.h>
#include <iostream>
using namespace std;

int abs(int x) {
	return x<0?-x:x;
}

long long max(long long a, long long b) {
	return a>b?a:b;
}

int main(){
	int cse = 1,
		n, x[20], negs[20];
	long long p[20] = {1};

	while (cin>>n) {
		long long mx = 0;

		bool done = 0;
		while (!done) {
			int nn = n,
				ncnt = 0;
			
			done = 1;
			for (int i=1; i<=n; i++) {
				cin>>x[i];
				if (!x[i]) {
					done = 0;
					nn = i-1;
					n -= i;
					break;
				}

				p[i] = p[i-1]*abs(x[i]);
				if (x[i]<0) negs[ncnt++] = i;
			}

			if (nn>0) {
				if (!(ncnt&1)) mx = max(mx, p[nn]);
				else for (int i=0; i<ncnt; i++) {
					int ind = negs[i];
					if (ind>1)
						mx = max(mx, p[ind-1]);
					if (ind < nn)
						mx = max(mx, p[nn]/p[ind]);
				}
			}
		}

		printf("Case #%d: The maximum product is %lld.\n\n", cse++, mx);
	}
}
