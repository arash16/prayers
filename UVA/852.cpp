#include <bits/stdc++.h>
using namespace std;

bool S[10][10];
char M[10][10];
int dcolor(int i, int j) {
	if (M[i][j] != '.')
		return M[i][j]=='O' ? 1 : 2;

	if (S[i][j]) return 0;
	S[i][j] = 1;

	int res = 0;
	if (res<3 && i>0) res |= dcolor(i-1, j);
	if (res<3 && i<8) res |= dcolor(i+1, j);
	if (res<3 && j>0) res |= dcolor(i, j-1);
	if (res<3 && j<8) res |= dcolor(i, j+1);
	return res;
}

void dfill(int i, int j, char c) {
	if (M[i][j] != '.') return;
	M[i][j] = c;
	if (i>0) dfill(i-1, j, c);
	if (i<8) dfill(i+1, j, c);
	if (j>0) dfill(i, j-1, c);
	if (j<8) dfill(i, j+1, c);
}


int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);

	int T; cin >> T;
	while (T--) {
		for (int i=0; i<9; ++i)
			cin >> M[i];

		memset(S, 0, sizeof(S));
		for (int i=0; i<9; ++i)
			for (int j=0; j<9; ++j)
				if (M[i][j]=='.') {
					int c = dcolor(i, j);
					dfill(i, j, c==1?'O' : c==2?'X' : -1);
				}

		int bn=0, wn=0;
		for (int i=0; i<9; ++i)
			for (int j=0; j<9; ++j)
				if (M[i][j] == 'X') ++bn;
				else if (M[i][j] == 'O') ++wn;

		cout << "Black " << bn << " White " << wn << endl;
	}
}
