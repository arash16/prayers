#include <bits/stdc++.h>
using namespace std;

double rates[3][5] = {
    { 0.10, 0.25, 0.53, 0.87, 1.44 }, // 10
    { 0.06, 0.15, 0.33, 0.47, 0.80 }, // 4
    { 0.02, 0.05, 0.13, 0.17, 0.30 }  // 10
};


char BUF[1000000];
int main() {
    cout.rdbuf()->pubsetbuf(BUF, 1000000);
    ios_base::sync_with_stdio(0);cin.tie(0);

    char step, id[50];
    int h1, m1, h2, m2;
    while (cin >> step >> id >> h1 >> m1 >> h2 >> m2) {
        h1 = (h1 + 16) % 24;
        h2 = (h2 + 16) % 24;

        if (h1*60+m1 >= h2*60+m2)
            h2 += 24;

        int t1=0, t2=0, t3=0;
        for (int t=h1*60+m1; t<h2*60+m2; ++t) {
            int tt = t % (24 * 60);
            if (tt < 10*60) t1++;
            else if (tt < 14*60) t2++;
            else t3++;
        }

        int si = step-'A';
        printf("%10s%6d%6d%6d%3c%8.2f\n", id, t1, t2, t3, step,
            t1 * rates[0][si] + t2 * rates[1][si] + t3 * rates[2][si]);
    }
}
