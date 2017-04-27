#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);

	int n, p, x;
	for (int cse=1; cin>>p>>n && (n||p); ++cse) {
		list<int> q;
		for (int i=min(n,p); i>0; --i)
			q.push_front(i);
		
		cout << "Case " << cse << ":\n";
		for (int i=0; i<n; ++i) {
			char c;
			cin >> c;
			if (c == 'N') {
				cout << q.front() << endl;
				q.push_back(q.front());
				q.pop_front();
			}
			else {
				cin >> x;
				for (auto it=q.begin(); it!=q.end(); ++it)
					if (*it == x) {
						q.erase(it);
						break;
					}
				q.push_front(x);
			}
		}
	}
}
