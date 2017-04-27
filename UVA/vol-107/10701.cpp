#include <bits/stdc++.h>
using namespace std;


int main() {
	char s1[143], s2[143];
	int T, n, P[143];
	cin >> T;
	while (T--) {
		cin >> n >> s1 >> s2;
		for (int i=0; i<n; ++i)
			P[s1[i]] = i;

		stack<char> st;
		for (int i=0; i<n; ++i) {
			while (!st.empty() && P[st.top()] > P[s2[i]]) {
				cout << st.top();
				st.pop();
			}

			if (i<n-1 && P[s2[i]] > P[s2[i+1]])
				cout << s2[i];
			else st.push(s2[i]);
		}

		while (!st.empty()) {
			cout << st.top();
			st.pop();
		}

		cout << endl;
	}
}
