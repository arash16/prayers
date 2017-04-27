#include <bits/stdc++.h>
using namespace std;

char M[200][200];
bool isstar(int y, int x) {
	if (M[y][x]!='*') return 0;
	for (int i=-1; i<2; ++i)
		for (int j=-1; j<2; ++j)
			if ((i || j) && M[y+i][x+j]=='*')
				return 0;
	return 1;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);


	int n, m;
	while (cin>>n>>m && (n||m)) {
		memset(M[n+1], 0, m+2);
		for (int i=1; i<=n; ++i)
			cin >> (M[i]+1);

		int cnt = 0;
		for (int i=1; i<=n; ++i)
			for (int j=1; j<=m; ++j)
				if (isstar(i, j))
					++cnt;
		cout << cnt << endl;
	}
}
