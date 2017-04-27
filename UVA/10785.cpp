#include <bits/stdc++.h>
using namespace std;

char cons[] = "JSBKTCLDMVNWFXGPYHQZR", // 5
	 vows[] = "AUEOI"; // 21
int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);

	int T, n;
	cin >> T;
	for (int cse=1; cse<=T; ++cse) {
		cout << "Case " << cse << ": ";
		cin >> n;
		int cn=0, vn=0;
		vector<char> v1, v2;
		for (int k=0, i=0, j=0; k<n; ++k) {
			if (k % 2) {
				v2.push_back(cons[i]);
				if (++cn == 5) {
					cn = 0;
					++i;
				}
			}
			else {
				v1.push_back(vows[j]);
				if (++vn == 21) {
					vn = 0;
					++j;
				}
			}
		}
		sort(v1.begin(), v1.end());
		sort(v2.begin(), v2.end());
		for (int i=0; i<v1.size(); ++i) {
			cout << v1[i];
			if (i < v2.size())
				cout << v2[i];
		}
		cout << "\n";
	}
}
