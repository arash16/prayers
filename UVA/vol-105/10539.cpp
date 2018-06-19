#include <bits/stdc++.h>
using namespace std;


bool isnp[1000143];
long long v[80070];
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int sz = 0;
    for (long long j=4; j<1e12; j*=2)
        v[sz++] = j;

    for (int i=3; i<1000143; i+=2)
        if (!isnp[i]) {
            for (long long j=(long long)i*i; j<1e12; j*=i)
                v[sz++] = j;

            for (int j=i+i; j<1000143; j+=i)
                isnp[j] = 1;
        }
    sort(v, v+sz);

    long long T, l, h;
    cin >> T;
    while (T-- && cin >> l >> h) {
        cout << upper_bound(v, v+sz, h)-lower_bound(v, v+sz, l) << endl;
    }
}
