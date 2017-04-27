#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int dh[20001], kh[20001];

int main(){
	while(cin>>n>>m && (n||m)) {
		int mindh=2147483647;
		for (int i=0; i<n; i++) {
			cin>>dh[i];
			if (dh[i]<mindh) mindh=dh[i];
		}

		for (int i=0; i<m; i++) {
			cin>>kh[i];
			if (kh[i]<mindh) i--, m--; // filter low knights
		}

		int res = 0;
		bool doomed = false;
		if (n > m) doomed = true;
		else {
			sort(dh, dh+n);
			sort(kh, kh+m);
			int j=-1;
			for (int i=0; !doomed && i<n; i++) {
				for (j++; j<m && kh[j]<dh[i]; j++);
				if (m-j < n-i) doomed=true;
				else res += kh[j];
			}
		}
		if (doomed) cout << "Loowater is doomed!\n";
		else cout << res << endl;
	}
}
