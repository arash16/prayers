#include <bits/stdc++.h>
using namespace std;


int X[143], C[143], R[143], len, sz;
bool bt(int si, int sum, int cnt, bool st) {
    if (sum == len) return bt(0, 0, cnt-1, 1);
    if (!cnt) return 1;
    if (sum + C[si]*X[si] + R[si+1] < len)
        return 0;

    if (st) {
        int i=0;
        while (!C[i]) ++i;
        --C[i];
        int result = bt(i, sum+X[i], cnt, 0);
        ++C[i];
        return result;
    }

    for (int i=si; i<sz; ++i)
        if (C[i]>0 && sum+X[i]<=len) {
            --C[i];
            if (bt(i, sum+X[i], cnt, 0)) return 1;
            ++C[i];

            if (sum + X[i] == len) return 0;
        }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int n;
    while (cin >> n && n) {
        int sum = 0, mx=0;
        for (int i=0; i<n; ++i) {
            cin >> X[i];
            sum += X[i];
            mx = max(mx, X[i]);
        }

        sort(X, X+n, greater<int>());
        sz = C[0] = 1;
        for (int i=1; i<n; ++i)
            if (X[i] != X[i-1])
                X[sz++] = X[i],
                C[sz-1] = 1;
            else
                C[sz-1]++;

        R[sz] = 0;
        for (int i=sz-1; i>=0; --i)
            R[i] = R[i+1] + C[i]*X[i];

        int found = -1;
        int hsum = sum>>1;
        for (len=mx; found<0 && len<=hsum; ++len)
            if (sum%len==0 && bt(0, 0, sum/len, 1))
                found = len;

        cout << (found<0 ? sum : found) << '\n';
    }
}
