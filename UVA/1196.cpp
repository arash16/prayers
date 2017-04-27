#include <stdio.h>
#include <algorithm>
#include <list>
using namespace std;

#define MAX 10005
int X[MAX], Y[MAX];
bool comp(int i, int j) { 
	return X[i] != X[j] 
		? X[i] < X[j] 
		: Y[i] < Y[j];
}

int main() {
	int n, order[MAX], M[MAX];

	while (scanf("%d", &n)==1 && n) {
		for (int i=0; i<n; i++) {
			scanf("%d%d", X+i, Y+i);
			order[i] = i;
		}
		sort(order, order+n, comp);

		int len = 0;
		for (int i=0; i<n; i++) {
			int u = order[i],
				lo=1, hi=len;
			while (lo <= hi) {
				int mid = (lo+hi)>>1;
				if (Y[M[mid]] <= Y[u])
					 lo = mid + 1;
				else hi = mid - 1;
			}
			M[lo] = u;
			len = max(len, lo);
		}
		printf("%d\n", len);
	}
	puts("*");
}
