#include <stdio.h>
#include <cstring>
#include <iostream>
using namespace std;

bool has3(int x) {
	for (int i=0; i<3; i++) {
		if (!x) return false;
		x -= x & -x;
	}
	return true;
}

int main(){
	int n, m, cons[26];
	char w[100];
	while (scanf("%d%d %s", &n, &m, w)==3) {
		int iter, naw=1, aw = 0;
		memset(cons, 0, sizeof(cons));
		for (int i=0; i<3; i++)
			aw |= 1 << (w[i] - 'A');

		for (int i=0; i<m; i++) {
			scanf("%s", w);
			int u=w[0]-'A', v=w[1]-'A';
			cons[u] |= 1<<v;
			cons[v] |= 1<<u;
		}

		if (has3(aw)) n-=3;
		for (iter=0; naw && n; iter++) {
			naw = 0;
			for (int i=0, k=1; i<26; i++, k<<=1)
				if (cons[i] && !(aw&k))
					if (has3(cons[i] & aw)) {
						naw |= k;
						n--;
					}
			aw |= naw;
		}

		if (n) puts("THIS BRAIN NEVER WAKES UP");
		else printf("WAKE UP IN, %d, YEARS\n", iter);
	}
}
