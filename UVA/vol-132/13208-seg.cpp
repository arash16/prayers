#include <bits/stdc++.h>
using namespace std;


long long C[10143];
int R[80143], H[10143], X[10143], n;
int rmq(int qs, int qe, int ss=0, int se=n+1, int id=1) {
    if (qs<=ss && qe>=se) return R[id];
    if (qs>=se || qe<=ss) return n+1;

    int mid = (ss + se) >> 1,
        i1 = rmq(qs, qe, ss, mid, id<<1),
        i2 = rmq(qs, qe, mid, se, id<<1|1);

    return H[i1] > H[i2] ? i1 : i2;
}

int build(int ss=0, int se=n+1, int id=1) {
    if (ss+1 == se) return R[id] = ss;
    if (ss >= se) return R[id] = n+1;

    int mid = (ss + se) >> 1,
        i1 = build(ss, mid, id<<1),
        i2 = build(mid, se, id<<1|1);

    return R[id] = H[i1] > H[i2] ? i1 : i2;
}


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int T, a;
    cin >> T;
    while (T-- && cin >> a >> n) {
        for (int i=1; i<=n; ++i) {
            cin >> X[i];
            C[i] = C[i-1] + X[i];
        }

        for (int j=0; j<=n; ++j)
            cin >> H[j];
        H[n+1] = -1;
        build();

        int mxi = 0;
        for (int j=1; j<=n; ++j)
            if (H[j] > H[mxi])
                mxi = j;

        long long sum = 0;
        for (int i=mxi; i<n; ) {
            int ni = rmq(i+1, n+1);
            sum += (C[ni]-C[i]) * min(H[i], H[ni]) * a;
            i = ni;
        }

        for (int i=mxi; i>0; ) {
            int ni = rmq(0, i);
            sum += (C[i]-C[ni]) * min(H[i], H[ni]) * a;
            i = ni;
        }

        cout << sum << endl;
    }
}
