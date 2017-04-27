#include <stdio.h>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

int main() {
	int n, d, r, A[102], B[102]; bool used[102];
	while (cin>>n>>d>>r && (n||d||r)) {
		for (int i=0; i<n; i++)
			cin>>A[i];

		for (int i=0; i<n; i++)
			cin>>B[i];

		sort(A, A+n, greater<int>());
		sort(B, B+n);

		int sum=0;
		memset(used, 0, n);
		for (int i=0; i<n; i++) {
			int best = d - A[i];
			int ind = lower_bound(B, B+n, best) - B;
			if (ind > 0) ind--;
			if (used[ind]) for(ind=0; used[ind]; ind++);
			used[ind] = true;

			if (A[i] + B[ind] > d)
				sum += A[i] + B[ind] - d;
		}

		cout << sum*r << endl;
	}
}
