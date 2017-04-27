#include <bits/stdc++.h>
#define INF 2147483647
using namespace std;

int C[143][143], n;
int CS(int i1, int i2, int j) {
	if (i2 > n) i2 -= n;
	if (i1 == i2) return -INF;
	int result = C[i2][j] - C[i1][j];
	if (i2 < i1) result += C[n][j];
	return result;
}


int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);

	int T; cin >> T;
	while (T--) {
		cin >> n;
		for (int i=1; i<=n; ++i)
			for (int j=0, x; j<n; ++j) {
				cin >> x;
				C[i][j] = C[i-1][j] + x;
			}

		int bs = -INF;
		for (int i1=0; i1<n; ++i1)
			for (int i2=i1+1; i2-i1<=n; ++i2) 
				for (int j1=0; j1<n; ++j1) {
					int sum=0;
					for (int j2=j1; j2-j1<n && sum>=0; ++j2)
						bs = max(bs, sum += CS(i1, i2, j2%n));
				}
		
		cout << bs << endl;
	}
}
