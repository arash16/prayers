#include <bits/stdc++.h>
using namespace std;

#define MAXN 500000
char prob[MAXN], stat[MAXN];
int tid[MAXN], hr[MAXN], mn[MAXN], ord[MAXN];
bool complog(int i, int j) { 
	int t1 = hr[i]*60+mn[i],
		t2 = hr[j]*60+mn[j];
	return t1 != t2 ? t1 < t2
					: stat[i] < stat[j];
}

int ttime[30], solvn[30], tnum[30];
bool comp(int i, int j) {
	if (solvn[i] != solvn[j])
		return solvn[i] > solvn[j];

	if (ttime[i] != ttime[j])
		return ttime[i] < ttime[j];

	return i < j;
}


int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);

	char line[1000];
	int T, n, tn;
	cin >> T;
	cin.getline(line, 1000);
	cin.getline(line, 1000);
	while (T--) {
		for (n=tn=0; cin.getline(line, 1000) && line[0]; ++n) {
			sscanf(line, "%d %c %d:%d %c", tid+n, prob+n, hr+n, mn+n, stat+n);
			if (tid[n] > tn) tn = tid[n];
			ord[n] = n;
		}
		sort(ord, ord+n, complog);

		for (int i=0; i<tn; ++i) {
			ttime[i] = solvn[i] = 0;
			tnum[i] = i;
		}

		int pen[26][7] = {};
		bool solved[26][7] = {};
		for (int i=0; i<n; ++i) {
			int j = ord[i],
				p = prob[j]-'A',
				ti = tid[j] - 1;

			if (solved[ti][p]) continue;
			if (stat[j] == 'Y') {
				solved[ti][p] = 1;

				++solvn[ti];
				ttime[ti] += hr[j]*60 + mn[j] + 20*pen[ti][p];
			}
			else ++pen[ti][p];
		}
		sort(tnum, tnum+tn, comp);

		cout << "RANK TEAM PRO/SOLVED TIME\n";
		for (int i=0, lr, lti; i<tn; ++i) {
			int ti = tnum[i];
			if (!i || solvn[ti]<solvn[lti] || ttime[ti] > ttime[lti])
				lr = i+1;

			cout << setw(4) << lr
				 << setw(5) << (ti+1);

			if (solvn[ti])
				cout << setw(5) << solvn[ti] << "      "
					 << setw(5) << ttime[ti];
			cout << endl;

			lti = ti;
		}
		if (T) cout << endl;
	}
}
