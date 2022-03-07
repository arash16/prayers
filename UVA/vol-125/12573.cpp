/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 12573
  Name: Sohel Sir's Assignment
  Problem: https://onlinejudge.org/external/125/12573.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long Int;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    Int T, x, y;
    cin >> T;
    while (T-- && cin >> x >> y) {
        Int n = x-y+2,
            sq = sqrt(n),
            mn = Int(1e14);

        if (y < 2) mn = 1;
        else if (n<=0) mn = x+1;
        else
            for (Int i=1; i<=sq; ++i)
                if (n % i == 0) {
                    if (x%i == y-2)
                        mn = min(mn, i);

                    if (x % (n/i) == y-2)
                        mn = min(mn, n/i);

                    if (i > mn) break;
                }

        if (mn < Int(1e14))
             cout << mn << '\n';
        else cout << "Impossible\n";
    }
}
