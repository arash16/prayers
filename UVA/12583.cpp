#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);

	int T, n, k, L[26];
	cin >> T;
	for (int cse=1; cse<=T; ++cse) {
		string str;
		cin >> n >> k >> str;

		int cnt=0;
		for (int i=0; i<26; ++i) L[i] = -k - 1;
		for (int i=0; i<n; ++i) {
			int id = str[i] - 'A';
			if (i - L[id] <= k)
				++cnt;
			L[id] = i;
		}

		cout << "Case " << cse << ": " << cnt << '\n';
	}
}
