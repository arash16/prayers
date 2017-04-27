#include <bits/stdc++.h>
using namespace std;


char fnames[6][10] = {
	"front", "back", 
	"left", "right", 
	"top", "bottom"
};

int C[555][6], D[555][6], n;
struct State {
	int i, j, d;
	State():i(0),j(0),d(0){}
	State(int i, int j, int d):i(i),j(j),d(d){}
	bool operator < (const State &o) const { return d+i < o.d+o.i; }
} P[555][6];


char BUF[1000000];
int main() {
	cout.rdbuf()->pubsetbuf(BUF, 1000000);
	ios_base::sync_with_stdio(0);cin.tie(0);

	for (int cse=1; cin>>n && n; ++cse) {
		priority_queue<State> q;

		for (int i=0; i<n; ++i)
			for (int j=0; j<6; ++j) {
				cin >> C[i][j];
				q.push(State(i, j, D[i][j]=1));
			}

		State best;
		while (!q.empty()) {
			State s = q.top(); q.pop();
			if (D[s.i][s.j] != s.d || s.d+s.i<best.d) continue;
			if (best.d < s.d) best = s;

			int tc = C[s.i][s.j];
			for (int i=0; i<s.i; ++i)
				for (int j=0; j<6; ++j)
					if (C[i][j^1]==tc && s.d+1>D[i][j])
						q.push(State(i, j, D[i][j]=s.d+1)),
						P[i][j] = s;
		}

		if (cse > 1) cout << "\n";
		cout << "Case #" << cse << "\n" << best.d << "\n";
		for (int i=best.d; i>0; --i) {
			cout << best.i+1 << ' ' << fnames[best.j] << "\n";
			best = P[best.i][best.j];
		}
	}
}
