#include <bits/stdc++.h>
using namespace std;

#define MAXN 105
char M[MAXN][MAXN];
int S[MAXN][MAXN], mxc[MAXN], w, h;
void dfs(int y, int x, int id) {
	if (S[y][x]) return;
	S[y][x] = id;

	char cc = M[y][x];
	for (int i=-1; i<2; ++i)
		for (int j=-1; j<2; ++j) if (i||j) {
			int ny=y+i, nx=x+j;
			if (ny>=0 && ny<h && nx>=0 && nx<w && M[ny][nx]==cc)
				dfs(ny, nx, id);
		}
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);

	char str[1024];
	while (1) {
		for (h=0; cin.getline(str, 1024) && str[0] && str[0]!='%'; ++h) {
			w = 0;
			for (int i=0; str[i]; ++i)
				if (str[i] != ' ') {
					M[h][w] = str[i];
					S[h][w++] = 0;
				}
		}
		if (!h) break;

		int id = 0;
		for (int i=0; i<h; ++i)
			for (int j=0; j<w; ++j)
				if (!S[i][j])
					dfs(i, j, ++id);

		for (int j=0; j<w; ++j) {
			mxc[j] = 0;
			for (int i=0; i<h; ++i)
				mxc[j] = max(mxc[j], S[i][j]);
			mxc[j] = int(log10(mxc[j])) + 1 + (j>0);
		}

		for (int i=0; i<h; ++i) {
			for (int j=0; j<w; ++j)
				cout << setw(mxc[j]) << S[i][j];
			cout << endl;
		}
		cout << "%\n";
	}
}
