#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

#define INF 1073741824

struct Block {
	int x, y, z;
	Block () {}
	Block (int x, int y, int z): x(x), y(y), z(z) {}
	bool operator < (const Block& b) const {
		return x<b.x && y<b.y;
	}
};
Block blocks[100];
int n;

bool seen[100];
int o[100], cnt;
void dfs(int u) {
	if (seen[u]) return;
	seen[u] = true;
	
	for (int i=0; i<n; i++)
		if (blocks[u] < blocks[i])
			dfs(i);

	o[--cnt] = u;
}






int DP[100][100];
int main(){
	int cse=1, bn;
	while (cin>>bn && bn) {
		n = 3*bn;
		for (int i=0; i<bn; i++) {
			int a[3];
			cin>>a[0]>>a[1]>>a[2];
			sort(a, a+3);
			blocks[3*i+0] = Block(a[0], a[1], a[2]);
			blocks[3*i+1] = Block(a[0], a[2], a[1]);
			blocks[3*i+2] = Block(a[1], a[2], a[0]);
		}
		blocks[n] = Block(INF, INF, 0);
		o[n]=n;
		
		for (int i=0; i<n; i++) seen[i]=0;

		// TOPO SORT
		cnt = n;
		for (int i=0; cnt>=0; i++)
			dfs(i);

		int j;
		Block &b0 = blocks[o[0]];
		for (j=1; j<=n; j++)
			DP[0][j] = b0<blocks[o[j]] ? b0.z : 0;

		for (int i=1; i<n; i++) {
			Block &bi = blocks[o[i]];
			for (j=i+1; j<=n; j++)
				if (bi < blocks[o[j]])
					DP[i][j] = max(DP[i-1][i] + bi.z, DP[i-1][j]);
				else
					DP[i][j] = DP[i-1][j];
		}
		
		printf("Case %d: maximum height = %d\n", cse++, DP[n-1][n]);
	}
}
