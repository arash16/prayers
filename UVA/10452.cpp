#include <bits/stdc++.h>
using namespace std;

char ph[] = "IEHOVA#", M[17][17];
int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);

	int T, n, m;
	cin >> T;
	while (T--) {
		cin >> n >> m;
		for (int i=1; i<=n; ++i)
			cin >> (M[i]+1);

		for (int j=1; j<=m; ++j)
			if (M[n][j] == '@') {
				for (int ci=n, cj=j, d=0; M[ci][cj]!='#'; ++d) {
					if (M[ci][cj-1] == ph[d]) {
						cout << "left"; --cj;
					}
					else if (M[ci][cj+1] == ph[d]) {
						cout << "right"; ++cj;
					}
					else {
						cout << "forth"; --ci;
					}
					if (M[ci][cj]!='#') cout << ' ';
				}
				cout << '\n';
				break;
			}
	}
}
