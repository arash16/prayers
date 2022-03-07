/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10061
  Name: How many zero's and how many digits ?
  Problem: https://onlinejudge.org/external/100/10061.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
#define INF 2147483647
using namespace std;


int count(int n, int k) {
    int r = 0;
    for (int i=k, t; (t=n/i); i*=k)
        r += t;
    return r;
}

int TZ(int n, int b) {
    int r = INF, m=b;
    for (int i=2; i*i<=m; ++i)
        if (m%i == 0) {
            int c = 0;
            while (m%i == 0)
                m /= i,
                c++;

            r = min(r, count(n, i)/c);
        }
    if (m > 1)
        r = min(r, count(n, m));
    return r;
}

double LF[(1<<20)+1];
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    for (int i=1; i<=(1<<20); ++i)
        LF[i] = LF[i-1] + log(i);

    int n, b;
    while (cin >> n >> b) {
        cout << TZ(n, b) << ' ' << int(LF[n]/log(b)+1) << endl;
    }
}
