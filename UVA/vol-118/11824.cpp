#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int T, n;
	cin >> T;
	while (T--) {
		priority_queue<int> q;
		while (cin>>n && n)
			q.push(n);

		int sum = 0;
		for (int i=1; !q.empty(); ++i) {
			sum += 2 * pow(q.top(), i);
			if (sum > 5000000) break;
			q.pop();
		}

		if (q.empty()) printf("%d\n", sum);
		else puts("Too expensive");
	}
}
