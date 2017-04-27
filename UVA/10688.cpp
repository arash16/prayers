#include <bits/stdc++.h>
#define INF 268435456
using namespace std;

int DP[1000][1000];
int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);

	for (int n=2; n<=500; ++n)
		for (int k=0; n+k<=500; ++k) {
			int mn = INF;
			for (int i=0; i<n; ++i) {
				int tt = 
					DP[i][k] +
					n * (k + i + 1) +
					DP[n-i-1][k+i+1];
				
				if (tt < mn) mn = tt;
			}
			DP[n][k] = mn;
		}

	int T;
	cin >> T;
	for (int cse=1, n, k; cse<=T && cin >> n >> k; ++cse)
		cout << "Case " << cse << ": " << DP[n][k] << "\n";
}

