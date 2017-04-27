#include <bits/stdc++.h>
#define INF 2147483647
using namespace std;


struct State {
	int i, j, d;
	State(int i, int j, int d):i(i),j(j),d(d){}
	bool operator < (const State &o) const {
		return d != o.d ? d > o.d
			: i > o.i;
	}
};


int D[143][143], M[143][143], P[143][143], path[143], n, m;
int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);

	while (cin >> n >> m) {
		priority_queue<State> q;
		for (int i=0; i<n; ++i) {
			for (int j=0; j<m; ++j) {
				cin >> M[i][j];
				D[i][j] = INF;
			}
			M[i][m] = 0; D[i][m] = INF;
			q.push(State(i, 0, D[i][0]=M[i][0]));
		}

		while (!q.empty()) {
			State s = q.top(); q.pop();
			if (D[s.i][s.j] != s.d) continue;
			if (s.j == m) {
				int sz = 0;
				for (int j=m-1, i=P[s.i][s.j]; j>=0; --j) {
					path[sz++] = i;
					i = P[i][j];
				}

				cout << path[sz-1]+1;
				for (int i=sz-2; i>=0; --i)
					cout << ' ' << path[i]+1;
				cout << '\n';
				cout << s.d << '\n';
				break;
			}

			for (int k=-1; k<2; ++k) {
				int ii = (s.i + k +n)%n;
				State t(ii, s.j+1, s.d + M[ii][s.j+1]);
				if (D[t.i][t.j] > t.d) {
					D[t.i][t.j] = t.d;
					P[t.i][t.j] = s.i;
					q.push(t);
				}
			}
		}
	}
}
