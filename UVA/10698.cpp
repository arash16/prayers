#include <bits/stdc++.h>
using namespace std;

char tname[30][30], t1[30], t2[30], tmp[30];
int ord[30], pts[30], played[30], goals[30], suff[30], g1, g2, n, m;
bool comp(int i, int j) {
	if (pts[i] != pts[j]) return pts[i] > pts[j];
	int d1 = goals[i]-suff[i], d2 = goals[j]-suff[j];
	if (d1 != d2) return d1 > d2;
	if (goals[i] != goals[j]) return goals[i] > goals[j];
	return strcasecmp(tname[i], tname[j]) < 0;
}

bool eqteam(int i, int j) {
	return pts[i]==pts[j] && goals[i]==goals[j] && suff[i] == suff[j];
}


int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	bool frst = 1;
	while (cin>>n>>m && (n||m)) {
		if (frst) frst = 0;
		else cout << endl;

		unordered_map<string, int> tid;

		for (int i=0; i<n; ++i) {
			cin >> tname[i];
			tid[tname[i]] = ord[i] = i;
			pts[i] = played[i] = goals[i] = suff[i] = 0;
		}

		int total = 0;
		for (int i=0; i<m; ++i) {
			cin >> t1 >> g1 >> tmp >> g2 >> t2;
			int id1 = tid[t1], id2 = tid[t2];
			++played[id1];
			++played[id2];
			goals[id1] += g1;
			goals[id2] += g2;
			suff[id1] += g2;
			suff[id2] += g1;
			if (g1 == g2) {
				++pts[id1];
				++pts[id2];
				--total;
			}
			else if (g1 > g2)
				 pts[id1] += 3;
			else pts[id2] += 3;
			total += 3;
		}

		sort(ord, ord+n, comp);
		for (int i=0; i<n; ++i) {
			int ti = ord[i];
			if (i && eqteam(ti, ord[i-1])) cout << "   ";
			else cout << setw(2) << (i+1) << '.';
			cout << setw(16) << tname[ti]
				 << setw(4) << pts[ti] 
				 << setw(4) << played[ti] 
				 << setw(4) << goals[ti] 
				 << setw(4) << suff[ti] 
				 << setw(4) << (goals[ti]-suff[ti]);

			if (played[ti]) 
				cout << setw(7) << fixed << setprecision(2) 
					 << (100.0 * pts[ti] / (played[ti]*3)) << endl;
			else cout << "    N/A\n";
		}
	}
}
