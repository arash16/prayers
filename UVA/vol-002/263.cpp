/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 263
  Name: Number Chains
  Problem: https://onlinejudge.org/external/2/263.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;


int T[] = { 1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000 };
int nextNumber(int x, int &a, int &b) {
    char F[10] = {};
    for (; x; x/=10)
        ++F[x%10];

    a = b = 0;
    for (int i=0, j=0; i<10; ++i)
        while (F[i]--) {
            a = a*10 + i;
            b+= T[j++] * i;
        }
    return b - a;
}


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int n;
    while (cin >> n && n) {
        cout << "Original number was " << n << '\n';

        unordered_set<int> seen;
        int x=n, a, b, len=0;
        do {
            x = nextNumber(x, a, b);
            cout << b << " - " << a << " = " << x << '\n';
            ++len;
        }
        while (seen.emplace(x).second);
        cout << "Chain length " << len << "\n\n";
    }
}
