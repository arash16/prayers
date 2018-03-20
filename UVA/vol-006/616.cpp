#include <bits/stdc++.h>
using namespace std;


bool check(int n, int p) {
    for (int i=0; i<p; ++i)
        if (n % p != 1)
            return 0;
        else
            n -= (n/p) + 1;

    return n % p == 0;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int n;
    while (cin >> n && n>=0) {
        for (int i=21; i>0; --i)
            if (check(n, i)) {
                printf("%d coconuts, %d people and 1 monkey\n", n, i);
                goto fin;
            }
        printf("%d coconuts, no solution\n", n);
        fin:;
    }
}
