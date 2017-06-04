#include <bits/stdc++.h>
using namespace std;


struct Alignment {
    int p, t;
    bool operator < (const Alignment &o) const { return t < o.t; }
}
A[17];
int X[17], n, m;


bool used[17];
int M[5], P[17], bestM[5], bestP[17];
void bt(int idx, int sum, int ia) {
    int k;
    for (k=0; k<5 && M[k]==bestM[k]; ++k);
    if (k>=5 || M[k]>=bestM[k]) return;

    if (idx==n) {
        memcpy(bestM, M, sizeof(M));
        memcpy(bestP, P, n*sizeof(int));
        return;
    }

    for (int i=0; i<n; ++i)
        if (!used[i]) {
            used[i] = 1;
            P[idx] = i;

            int j, miss=0;
            for (j=ia; j<m && sum+X[i]>=A[j].t; ++j)
                M[A[j].p-1] += min(sum+X[i]-A[j].t, A[j].t-sum);

            bt(idx+1, sum+X[i], j);

            for (j=ia; j<m && sum+X[i]>=A[j].t; ++j)
                M[A[j].p-1] -= min(sum+X[i]-A[j].t, A[j].t-sum);

            used[i] = 0;
        }
}


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    for (int cse=1; cin >> n && n; ++cse) {
        int sum = 0;
        for (int i=0; i<n; ++i) {
            cin >> X[i];
            sum += X[i];
        }

        cin >> m;
        for (int i=0; i<m; ++i)
            cin >> A[i].p >> A[i].t;
        sort(A, A+m);

        memset(bestM, 127, sizeof(bestM));
        memset(M, 0, sizeof(M));
        for (int i=0; i<m; ++i)
            if (A[i].t > sum)
                M[A[i].p-1] += A[i].t - sum;

        bt(0, 0, 0);

        int err = 0;
        for (int i=0; i<5; ++i)
            err += bestM[i];

        cout << "Data set " << cse << "\nOrder:";
        for (int i=0; i<n; ++i)
            cout << ' ' << X[ bestP[i] ];
        cout << "\nError: " << err << '\n';
    }
}
