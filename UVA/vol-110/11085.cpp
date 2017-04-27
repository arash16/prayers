#include <bits/stdc++.h>
using namespace std;

int P[8], best;
bool check(int j) {
	for (int i=0; i<j; ++i)
		if (P[i]==P[j] || j-i==abs(P[j]-P[i]))
			return false;

	return true;
}

int pp[143][8], ppn;
void bt(int j) {
	if (j == 8) {
		memcpy(pp[ppn++], P, 32);
		return;
	}

	for (int i=1; i<=8; ++i) {
		P[j] = i;
		if (check(j))
			bt(j+1);
	}
}


int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);

	bt(0);
	for (int cse=1; cin >> P[0]; ++cse) {
		for (int i=1; i<8; ++i)
			cin >> P[i];

		int mn = 10;
		for (int i=0; i<ppn; ++i) {
			int cnt = 0;
			for (int j=0; j<8; ++j)
				if (pp[i][j] != P[j])
					++cnt;

			mn = min(mn, cnt);
		}

		cout << "Case " << cse << ": " << mn << endl;
	}
}
