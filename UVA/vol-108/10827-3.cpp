#include <bits/stdc++.h>
#define INF 2147483647
using namespace std;

int X[155][155], C[155], n;
int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);

	int T; cin >> T;
	while (T--) {
		cin >> n;
		int bs = -INF;
		for (int i=0; i<n; ++i)
			for (int j=0, x; j<n; ++j) {
				cin >> x;
				bs = max(bs, X[i][j] = x);
			}

		if (bs > 0) {
			int tn = n<<1;
			for (int i1=0; i1<n; ++i1) {
				memset(C, 0, 2*n*sizeof(int));
				for (int i2=0; i2<n; ++i2) {
					for (int j=0; j<tn; ++j)
						C[j] += X[(i1+i2)%n][j%n];

					int sum = 0, lj=-1;
					for (int j=lj+1; j<tn; ++j) {
						bs = max(bs, sum += C[j]);
						if (sum < 0) {
							sum = 0;
							lj = j;
						}

						if (j - lj == n) {
							int nj = ++lj;
							sum -= C[lj];

							int tsum=0, mns=0;
							for (int k=lj+1; k<j; ++k) {
								tsum += C[k];
								if (tsum < mns) {
									mns = tsum;
									nj = k;
								}
							}
							sum -= mns;
							lj = nj;
						}
					}
				}
			}
		}

		cout << bs << endl;
	}
}
