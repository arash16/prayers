#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

int n, w[1001], DP[1001], P[1001] = {1, 2};
int main() {
	int T; cin>>T;
	while (T--) {
		cin>>n;
		for (int i=0; i<n; i++)
			cin >> w[i];
		sort(w, w+n);
		
		DP[0] = w[0];
		DP[1] = max(w[0], w[1]);
		for (int i=2; i<n; i++) {
			int oneOne = DP[i-1] + w[i] + w[0],
				twoOne = DP[i-2] + max(w[i], w[i-1]) + w[0] + 2*w[1];
			if (i==2 || oneOne < twoOne) {
				DP[i] = oneOne;
				P[i] = 1;
			}
			else {
				DP[i] = twoOne;
				P[i] = 2;
			}
		}

		cout << DP[n-1] << endl;
		if (n == 1) cout << w[0] << endl;
		else printf("%d %d\n", w[0], w[1]);

		for (int i=n-1; i>1; i -= P[i]) {
			cout << w[0] << endl;
			if (P[i] == 1)
				printf("%d %d\n", w[0], w[i]);
			
			else {
				printf("%d %d\n", w[i-1], w[i]);
				cout << w[1] << endl;
				printf("%d %d\n", w[0], w[1]);
			}
		}

		if (T) putchar('\n');
	}
}
