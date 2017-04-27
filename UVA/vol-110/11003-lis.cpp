#include <bits/stdc++.h>
using namespace std;


int W[1043], S[1043], M[1043]={2147483647}, n;
int LIS() {
	int L = 1;
	for (int i=0; i<n; ++i) {
		if (W[i] <= M[L-1]) {
			M[L] = min(M[L-1]-W[i], S[i]);
			++L;
		}

		for (int j=L-2; j>=0; --j)
			if (W[i] <= M[j])
				M[j+1] = max(M[j+1], min(M[j]-W[i], S[i]));
	}
	return L-1;
}


int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);

	while (cin>>n && n) {
		for (int i=0; i<n; ++i)
			cin >> W[i] >> S[i];

		cout << LIS() << "\n";
	}
}
