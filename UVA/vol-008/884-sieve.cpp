#include <bits/stdc++.h>
using namespace std;


const int MAXP = 1000003;
int C[MAXP];
int divcount(int n, int p) {
    int cnt = 0;
    while (n%p == 0) {
        n /= p;
        ++cnt;
    }
    return cnt;
}

void sieve() {
    for (int i=2; i<MAXP; ++i)
        if (!C[i]) {
            C[i] = 1;
            for (int j=i+i; j<MAXP; j+=i)
                C[j] += divcount(j, i);
        }
    for (int i=1; i<MAXP; ++i)
        C[i] += C[i-1];
}


int main() {
    sieve();

    int n;
    while (cin >> n)
        cout << C[n] << endl;
}
