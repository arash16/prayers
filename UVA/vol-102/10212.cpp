/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10212
  Name: The Last Non-zero Digit.
  Problem: https://onlinejudge.org/external/102/10212.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;


int powmod(int a, int b) {
    if (!b) return 1;
    int h = powmod(a, b/2); h *= h;
    return (b%2 ? h*a : h) % 10;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int n, m;
    while (cin >> n >> m) {
        int rs = 1, c2 = 0, c5 = 0;
        for (int i=n-m+1; i<=n; ++i) {
            int ii = i;
            while (ii % 2 == 0) {
                ii /= 2;
                c2 += 1;
            }
            while (ii % 5 == 0) {
                ii /= 5;
                c5 += 1;
            }
            rs = (rs * ii) % 10;
        }

        if (c2 > c5)
            rs *= powmod(2, c2-c5);
        else
            rs *= powmod(5, c5-c2);

        cout << rs%10 << endl;
    }
}

