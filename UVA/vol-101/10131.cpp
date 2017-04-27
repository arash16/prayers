#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

struct El {
	int w, s, ind;
	bool operator < (const El& e) const {
		return w == e.w ? s > e.w : w < e.w;
	}
};

El els[1001];
bool seen[1001];
int DP[1001], P[1001];

bool lt(int i, int j) {
	return els[i].w<els[j].w && els[i].s>els[j].s;
}



int main(){
	int n, l;
	for (n=0; cin >> els[n].w >> els[n].s; n++)
		els[n].ind = n+1;

	sort(els, els+n);

	int bestl=0, besti=0;
	for (int i=0; i<n; i++) {
		P[i] = -1;
		DP[i] = 1;
		for (int j=0; j<i; j++)
			if (DP[j]+1>DP[i] && lt(j, i)) {
				DP[i] = DP[j] + 1;
				P[i] = j;
			}

		if (DP[i]>bestl) {
			bestl=DP[i];
			besti=i;
		}
	}

	cout << bestl << endl;
	int *res = new int[bestl];
	int j=bestl-1;
	for (int i=besti; i!=-1; i = P[i])
		res[j--] = els[i].ind;

	for (int i=0; i<bestl; i++)
		cout << res[i] << endl;
}

