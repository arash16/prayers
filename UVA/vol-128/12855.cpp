#include <bits/stdc++.h>
using namespace std;


long long a, b;
long long calc(string s, int cs, int cl) {
    int rr = s.length()-1, ll = 0;
    for (int i=0; i<cl; ++i) {
        while (s[rr] == 'W') --rr;
        while (s[ll] == 'B') ++ll;
        swap(s[rr], s[ll]);
    }

    int ct = 0, fw = 0;
    for (int nb=fw; ; ++nb) {
        while (s[fw] == 'B') ++fw;
        nb = max(nb, fw);
        while (s[nb] == 'W') ++nb;
        if (!s[nb]) break;

        swap(s[fw], s[nb]);
        ct += nb-fw;
    }

    return cl*a + ct*b;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    string s;
    while (cin >> a >> b >> s) {
        b = a-b;

        int cb = 0;
        for (int i=0; s[i]; ++i)
            if (s[i] == 'B')
                ++cb;

        int cs = 0;
        for (int i=0; i<cb; ++i)
            if (s[i] == 'W')
                ++cs;

        long long price = 1LL<<43;
        int lo=0, hi=cs;
        while (lo <= hi) {
            int mid = (lo + hi) >> 1;
            long long
                pr1 = calc(s, cs, mid),
                pr2 = calc(s, cs, mid+1);

            price = min(price, min(pr1, pr2));
            if (pr1 < pr2)
                hi = mid - 1;
            else
                lo = mid + 1;
        }
        cout << price << '\n';
    }
}
