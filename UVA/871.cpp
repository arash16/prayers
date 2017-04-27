#include <bits/stdc++.h>
using namespace std;

char M[30][30], h, w;
int dfs(int y, int x) {
	int result = M[y][x] - '0';
	if (!result) return 0;
	
	M[y][x] = '0';
	for (int i=-1; i<2; ++i)
		for (int j=-1; j<2; ++j)
			if (i || j)
			if (y+i>=0 && y+i<h && x+j>=0 && x+j<w)
				result += dfs(y+i, x+j);
	
	return result;
}


int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);

	int T; cin >> T;
	cin.getline(M[0], 30);
	cin.getline(M[0], 30);
	
	while (T--) {
		for (h=w=0; cin.getline(M[h], 30) && M[h][0]; ++h);

		int mx = 0;
		w = strlen(M[0]);
		for (int i=0; i<h; ++i)
			for (int j=0; j<w; ++j)
				if (M[i][j] == '1')
					mx = max(mx, dfs(i, j));
		
		cout << mx << endl;
		if (T) cout << endl;
	}
}
