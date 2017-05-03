#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int X[200143], Y[200143], n;
    while (cin>>n && n) {
        for (int i=0; i<n; ++i)
            cin >> X[i] >> Y[i];

        int cnt1=0, cnt2=0;
        int xx = X[n>>1], yy = Y[n>>1];
        for (int i=0; i<n; ++i)
            if ((X[i]>xx && Y[i]>yy) || (X[i]<xx && Y[i]<yy))
                ++cnt1;
            else if (X[i]!=xx && Y[i]!=yy)
                ++cnt2;

        cout << cnt1 << ' ' << cnt2 << '\n';
    }
}
