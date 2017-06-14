#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int S[88], B[88], n;
    for (int cse=1; cin >> n && n; ++cse) {
        int A[1<<9] = {}, mxs = 0;
        for (int i=0; i<n; ++i) {
            int &b = B[i]; b=0;
            for (int j=0, x; j<3; ++j) {
                cin >> x;
                b |= 1 << (x-1);
            }
            cin >> S[i];
            A[b] = max(A[b], S[i]);
            mxs = max(mxs, S[i]);
        }

        int best = -1;
        for (int i=0; i<n; ++i) {
            if (S[i]+2*mxs <= best) continue;
            for (int j=i+1; j<n; ++j) {
                if (B[i]&B[j]) continue;

                int k = 511^B[i]^B[j];
                if (A[k]) best = max(best, S[i]+S[j]+A[k]);
            }
        }

        cout << "Case " << cse << ": " << best << '\n';
    }
}
