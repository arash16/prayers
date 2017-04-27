#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
	int cse = 1;
	int n, s, ev[110*110], ew[110*110], d[100];
	while (cin>>n && n) {
		cin>>s;
		
		int en;
		for (en=0; cin>>ev[en]>>ew[en]; en++)
			if (!ev[en] || !ew[en])
				break;

		for (int i=0; i<=n; i++)
			d[i] = 1000000;
		d[s] = 0;

		for (int i=0; i<n; i++)
			for (int i=0; i<en; i++)
				if (d[ev[i]] - 1 < d[ew[i]])
					d[ew[i]] = d[ev[i]] - 1;
		
		int v=s, vl=0;
		for (int i=1; i<=n; i++)
			if (d[i] < vl) {
				v = i;
				vl = d[i];
			}

		printf("Case %d: The longest path from %d has length %d, finishing at %d.\n\n", cse++, s, -vl, v);
	}
}
