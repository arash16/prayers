#include <bits/stdc++.h>
#define INF 67108864
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);

	char M[55][55];
	int T, n, m, D[55][55];
	cin >> T;
	for (int cse=1; cse<=T; ++cse) {
		cin >> n >> m;
		for (int i=0; i<n; ++i)
			cin >> M[i];
		
		for (int i=0; i<n; ++i) {
			int d = INF;
			for (int j=0; j<m; ++j) {
				if (M[i][j] == '0')
					d = 0;
				else ++d;
				D[i][j] = d;
			}
			
			d = INF;
			for (int j=m-1; j>=0; --j) {
				if (M[i][j] == '0')
					d = 0;
				else ++d;
				D[i][j] = min(D[i][j], d);
			}
		}
		
		int mxs = INF;
		for (int j=0; j<m; ++j) {
			int s = 0;
			for (int i=0; i<n; ++i)
				s += D[i][j];
			mxs = min(mxs, s);
		}
		cout << "Case " << cse << ": " << (mxs < INF ? mxs : -1) << "\n";
	}
}
