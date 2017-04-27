#include <bits/stdc++.h>
#define INF 2147483647
using namespace std;


struct State {
	int X[3], d;
	State(int a, int b, int c, int d):d(d){
		X[0] = a; X[1] = b; X[2] = c;
	}
	State(int Y[], int d):d(d){
		memcpy(X, Y, 3*sizeof(int));
	}
	bool operator < (const State& o) const { return d > o.d; }
};


int D[243][243][243], S[243][243][243];
int getD(int A[]) {
	return D[A[0]][A[1]][A[2]];
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);

	int T; cin>>T;
	for (int cse=1; cse<=T; ++cse) {
		int C[3], m;
		cin>>C[0]>>C[1]>>C[2]>>m;
		if (m > C[2]) m = C[2];

		int dp=0, dt=0;
		priority_queue<State> q;
		q.push(State(0,0,C[2], D[0][0][C[2]] = 0));
		while (!q.empty()) {
			State u = q.top(); q.pop();
			if (u.d != getD(u.X)) continue;
			for (int i=0; i<3; ++i)
				if (u.X[i] <= m && u.X[i]>dp) {
					dp = u.X[i]; dt = u.d;
					if (dp == m) goto fin;
				}

			for (int i=0; i<3; ++i) if (u.X[i]>0)
				for (int j=0; j<3; ++j) if (i!=j && u.X[j]<C[j]) {
					int dd = min(u.X[i], C[j]-u.X[j]);
					State v(u.X, u.d + dd);
					v.X[i] -= dd; v.X[j] += dd;
					if (S[v.X[0]][v.X[1]][v.X[2]]!= cse || v.d < getD(v.X)) {
						S[v.X[0]][v.X[1]][v.X[2]] = cse;
						D[v.X[0]][v.X[1]][v.X[2]] = v.d;
						q.push(v);
					}
				}
		}


		fin:
		cout << dt << ' ' << dp << endl;
	}
}
