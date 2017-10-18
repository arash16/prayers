#include <bits/stdc++.h>
using namespace std;


typedef unsigned int uint;
long long F[50] = { 1, 2 };
uint findNext(uint n, long long i) {
    long long j=i+1;
    if (n/j != n/i)
        return j;

    int fi = 0;
    while (n/j == n/i)
        j = i + F[++fi];

    return findNext(n, i + F[fi-1]);
}

long long H1(int n) {
    long long res = 0;
    for (uint i=1, j; i<=n; i = j) {
        j = n/i==1 ? n+1 : findNext(n, i);
        res += (j-i) * (n/i);
    }
    return res;
}

// ------------------------------------------

long long H2(int n) {
    long long res = 0;
    for (int j=1, k=n; ;j=n/k) {
        int r = n/j, l = n/(j+1);
        res += (long long) j * (r-l);
        k -= r-l;
        if (!k) break;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    for (int i=2; i<50; ++i)
        F[i] = F[i-1] + F[i-2];

    int T, n;
    cin >> T;
    while (T--) {
        cin >> n;
        cout << (n<1 ? 0 : H2(n)) << endl;
    }
}
