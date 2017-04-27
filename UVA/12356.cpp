#include <stdio.h>

int L[100016], R[100016], id[100016], cse=0;
void fix(int u) {
	if (id[u] != cse) {
		id[u] = cse;
		L[u] = u-1;
		R[u] = u+1;
	}
}

int main() {
	int s, n, a, b;
	while (scanf("%d%d", &s, &n)==2 && (s||n)) {
		cse++;
		fix(1);  fix(s);
		L[1] = R[s] = 0;
		for (int i=0; i<n; i++) {
			scanf("%d%d", &a, &b);
			fix(a); fix(L[a]);
			fix(b); fix(R[b]);

			if (!L[a]) printf("* ");
			else printf("%d ", L[a]);
			if (!R[b]) puts("*");
			else printf("%d\n", R[b]);
			R[L[a]] = R[b];
			L[R[b]] = L[a];
		}
		puts("-");
	}
}
