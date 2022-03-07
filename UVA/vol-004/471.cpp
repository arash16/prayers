/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 471
  Name: Magic Numbers
  Problem: https://onlinejudge.org/external/4/471.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;

bool seen[10];
int magics[10000000], cnt;
void generate(int x) {
    if (x < 100000)
    for (int i=!x; i<10; ++i)
        if (!seen[i]) {
            seen[i] = 1;
            generate(magics[cnt++] = x*10 + i);
            seen[i] = 0;
        }
}

bool ismagic(long long x) {
    bool seen[10]={};
    for (; x; x/=10) {
        int d = x%10;
        if (seen[d]) return 0;
        seen[d] = 1;
    }
    return 1;
}


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    generate(0);
    sort(magics, magics+cnt);

    int T;
    cin >> T;
    while (T--) {
        long long lst, n; cin >> n;
        for (int i=0; ; ++i) {
            if (i < cnt) lst = magics[i];
            else while (!ismagic(++lst));

            long long m = n * lst;
            if (m > 9876543210LL) break;
            if (ismagic(m))
                cout << m << " / " << lst << " = " << n << endl;
        }

        if (T) cout << endl;
    }
}
