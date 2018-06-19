#include <bits/stdc++.h>
using namespace std;


bool isnp[10143];
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    for (int i=2; i<10143; ++i)
        if (!isnp[i])
            for (int j=i+i; j<10143; j += i)
                isnp[j] = 1;

    int T, n;
    cin >> T;
    while (T-- && cin >> n) {
        int p = n/2 + 1;
        while (isnp[p]) ++p;
        cout << p << endl;
    }
}
