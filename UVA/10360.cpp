#include <stdio.h>
#include <cstring>
#include <iostream>
using namespace std;

#define MAXN 1026
int f[MAXN][MAXN];
int main() {
	int T, d, r, x, y, p;
	cin>>T;
	while (T--) {
		memset(f, 0, sizeof(f));
		cin>>d>>r;
		
		int maxp = 0, maxi=0, maxj=0;
		
		for (int i=0; i<r; i++) {
			cin >> x >> y >> p;

			int maxx = min(x+d, MAXN-1),
				maxy = min(y+d, MAXN-1);

			for (int i=max(0, x-d); i<=maxx; i++)
				for (int j=max(0, y-d); j<=maxy; j++) {
					int t = (f[i][j] += p);
					if (t >= maxp) 
						if (t > maxp || (i*MAXN+j < maxi*MAXN+j)) {
							maxp = t;
							maxi = i;
							maxj = j;
						}
				}
		}
		
		printf("%d %d %d\n", maxi, maxj, maxp);
	}
}
