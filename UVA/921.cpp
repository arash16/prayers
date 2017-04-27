#include <bits/stdc++.h>
using namespace std;
//
//
vector<int> C[110];
string D[120];
int n, m, l;
char R[26];
//
bool bt(int ind) {
	if (ind == n) {
		for (int i=0; i<l; ++i)
			if (!R[i]) return 0;
		return 1;
	}
//
//
	vector<int> &v = C[ind];
	for (int i=0; i<m; ++i)
		if (D[i].length() == v.size()) {
//
			for (int j=0; j<v.size(); ++j)
				if (R[v[j]] && R[v[j]] != D[i][j])
					goto fin;


			char rc[26];
			memcpy(rc, R, l);
			for (int j=0; j<v.size(); ++j)
				R[v[j]] = D[i][j];

			if (bt(ind+1)) return 1;
			memcpy(R, rc, l);
			fin:;
		}
	return 0;
}



int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
//
	char str[30];
	int T; cin>>T;
	while (T--) {
		int x;
		cin>>l>>n;
		for (int i=0; i<n; ++i) {
			C[i].clear();
			while (cin>>x && x) 
				C[i].push_back(x-1);
		}
		cin >> str;
//
		for (m=0; cin>>D[m] && D[m][0]!='*'; ++m);

		memset(R, 0, l+1);
		for (int i=0; str[i]; ++i)
			R[C[0][i]] = str[i];
//
		if (bt(0))
			cout << R << endl;
//
		else
			cout << "IMPOSSIBLE\n";
	}
}
