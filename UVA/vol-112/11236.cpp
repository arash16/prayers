#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int dm = 1000000;
    for (int i=1; i<=125; ++i)
        for (int j=i; j<=600; ++j)
            for (int k=j; i+j+k+k<=2000; ++k) if (i*j*k!=dm) {
                int l = dm*(i+j+k)/(i*j*k-dm);
                if (l>=k && i+j+k+l<=2000 && (i+j+k+l)*dm == i*j*k*l) {
                    cout << fixed << setprecision(2)
                         << i/100.0 << ' ' << j/100.0 << ' ' << k/100.0 << ' ' << l/100.0 << '\n';
                }
            }
}
