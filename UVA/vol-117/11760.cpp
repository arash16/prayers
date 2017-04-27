#include <cstring>
#include <stdio.h>

char msg[2][200] = {
	"Escaped again! More 2D grid problems!",
	"Party time! Let's find a restaurant!"
};

bool rs[10001], cs[10001];
int main() {
	int n, m, k, x, y, cse=1;
	while (scanf("%d%d%d", &n, &m, &k)==3 && (n||m||k)) {
		memset(rs, 0, n);
		memset(cs, 0, m);
		for (int i=0; i<k; ++i) {
			scanf("%d%d", &x, &y);
			rs[x] = 1;
			cs[y] = 1;
		}

		scanf("%d%d", &x, &y);
		printf("Case %d: %s\n", cse++, msg[ 
			(rs[x] || cs[y]) && 
			(rs[x] || (!y || cs[y-1]) && (y==m-1 || cs[y+1])) &&
			(cs[y] || (!x || rs[x-1]) && (x==n-1 || rs[x+1]))
		]);
	}
}
