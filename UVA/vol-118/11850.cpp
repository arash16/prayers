#include <bits/stdc++.h>
using namespace std;

int X[1500], n;
bool check() {
	make_heap(X, X+n);
	int lst = X[0]; pop_heap(X, X+n);
	if (1422-lst > 100) return 0;
	for (int i=1; i<n; ++i) {
		if (lst - X[0] > 200)
			return 0;
		
		lst = X[0];
		pop_heap(X, X+n-i);
	}
	return 1;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);

	while (cin>>n && n) {
		for (int i=0; i<n; ++i)
			cin >> X[i];
		
		puts(check() ? "POSSIBLE" : "IMPOSSIBLE");
	}
}
