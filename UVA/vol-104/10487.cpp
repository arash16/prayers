#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

#define INF 2147483647

int abs(int x) {
	return x<0 ? -x : x;
}

int main(){
	int cse=1, n, q, d, X[2000];
	while (cin>>n && n) {
		printf("Case %d:\n", cse++);
		for (int i=0; i<n; i++)
			cin>>X[i];
		sort(X, X+n);

		cin>>q;
		for (int j=0; j<q; j++) {
			cin >> d;
			long long int msd = INF, ms, diff, xt;
			for (int i=0; i<n; i++) {
				int ind = lower_bound(X, X+n, d-X[i]) - X,
					ib = ind-1-(ind-1==i),
					in = ind+(ind==i);

				if (in<n && in!=i) {
					xt = X[in];
					diff = abs(X[i]+xt-d);
					if (diff <= msd) {
						msd = diff;
						ms = X[i] + xt;
					}
				}
				
				if (ib >= 0 && ib!=i) {
					xt = X[ib];
					diff = abs(X[i]+xt-d);
					if (diff <= msd) {
						msd = diff;
						ms = X[i] + xt;
					}
				}
			}
			printf("Closest sum to %d is %lld.\n", d, ms);
		}
	}
}
