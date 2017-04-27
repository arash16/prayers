#include <bits/stdc++.h>
using namespace std;


int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	
	int X[10143], P[1000143], n;
	for (n=0; cin >> X[n]; ++n)
		P[X[n]] = n;

	sort(X, X + n);
	
	stack<int> st;
	for (int i=0; i<n; ++i) {
		while (!st.empty() && P[st.top()] > P[X[i]]) {
			cout << st.top() << endl;
			st.pop();
		}

		if (i < n-1 && P[X[i]] > P[X[i+1]])
			cout << X[i] << endl;
		else
			st.push(X[i]);
	}

	while (!st.empty()) {
			cout << st.top() << endl;
			st.pop();
	}
}
