#include <bits/stdc++.h>
using namespace std;


int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int T, n, m, x;
	cin>>T;
	while (T--) {
		int qs[10] = {};
		cin >> n >> m;
		queue<int> q;
		for (int i=0; i<n; ++i) {
			cin >> x;
			q.push(i==m ? -x : x);
			for (int y=1; y<x; ++y)
				++qs[y];
		}

		int sum = 1;
		for (;;) {
			int j = abs(q.front());
			if (qs[j]) q.push(q.front());
			else if (q.front()<0) break;
			else {
				++sum;
				for (int y=1; y<j; ++y)
					--qs[y];
			}
			q.pop();
		}

		cout << sum << endl;
	}
}
