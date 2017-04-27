#include <bits/stdc++.h>
using namespace std;

typedef pair<int, char> Pair;
bool comp(const Pair &p1, const Pair &p2) {
	return p1.first != p2.first
		? p1.first > p2.first
		: p1.second < p2.second;
}

int n, m;
char M[100][100];
int dfs(int y, int x, char ch) {
	if (M[y][x] != ch) return 0;
	M[y][x] = '.';

	int result = 1;
	if (x>0) result += dfs(y, x-1, ch);
	if (x<m-1) result += dfs(y, x+1, ch);
	if (y>0) result += dfs(y-1, x, ch);
	if (y<n-1) result += dfs(y+1, x, ch);

	return result;
}


int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);

	int cse=1;
	while (cin>>n>>m && (n||m)) {
		for (int i=0; i<n; ++i)
			cin >> M[i];

		vector<Pair> vec;
		for (int i=0; i<n; ++i)
			for (int j=0; j<m; ++j)
				if (M[i][j] != '.') {
					char ch = M[i][j];
					vec.push_back( Pair(dfs(i, j, ch), ch) );
				}
		sort(vec.begin(), vec.end(), comp);

		cout << "Problem " << (cse++) << ":\n";
		for (Pair &p: vec)
			cout << p.second << ' ' << p.first << endl;
	}
}
