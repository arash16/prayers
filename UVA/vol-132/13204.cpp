#include <bits/stdc++.h>
using namespace std;


bool seen[100];
int bf(int i, int s, int n) {
    if (i>n) return s == (n*n)>>1;

    int r = 0;
    for (int j=1; j<=n; ++j)
        if (!seen[j]) {
            seen[j] = 1;
            r += bf(i+1, s+fabs(i-j), n);
            seen[j] = 0;
        }
    return r;
}
// bf(1, 0, n)


#define MODUL 1000000007
int F[1000000] = { 1 };
int main() {
    for (long long i=1; i<1000000; ++i)
        F[i] = (F[i-1] * i) % MODUL;

    int n;
    while (cin >> n) {
        long long r = F[n>>1];
        r = (r * r) % MODUL;
        if (n&1) r = (r * n) % MODUL;
        cout << r << endl;
    }
}
