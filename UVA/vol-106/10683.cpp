#include <bits/stdc++.h>
using namespace std;


typedef long double ld;
char BUF[1000000];
int main() {
    cout.rdbuf()->pubsetbuf(BUF, 1000000);
    ios_base::sync_with_stdio(0);cin.tie(0);

    int hh, mm, ss, cc;
    while (scanf("%2d%2d%2d%2d", &hh, &mm, &ss, &cc)==4) {
        long long t = hh;
        t = t * 60 + mm;
        t = t * 60 + ss;
        t = t * 100+ cc;
        t = t * 10;

        hh = t / 8640000; t %= 8640000;
        mm = t / 86400; t %= 86400;
        ss = t / 864; t %= 864;
        cc = 100 * t / 864;
        printf("%d%02d%02d%02d\n", hh, mm, ss, cc);
    }
}
