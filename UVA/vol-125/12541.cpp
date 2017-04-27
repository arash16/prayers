#include <cstring>
#include <stdio.h>

int main() {
	char mns[30], mxs[30], name[30];
	int n, mn=10000000, mx=0, y, m, d;

	scanf("%d", &n);
	for (int i=0; i<n; ++i) {
		scanf("%s%d%d%d", name, &d, &m, &y);
		int t = y*366 + m*31 + d;
		if (t < mn) {
			strcpy(mns, name);
			mn = t;
		}

		if (t > mx) {	
			strcpy(mxs, name);
			mx = t;
		}
	}
	puts(mxs); puts(mns);
}
