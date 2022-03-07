/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 11371
  Name: Number Theory for Newbies
  Problem: https://onlinejudge.org/external/113/11371.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;


long long strtoi(const string &s) {
    long long r = 0;
    for (char c: s)
        r = r*10 + c-'0';
    return r;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    string str;
    while (cin >> str) {
        sort(str.rbegin(), str.rend());
        long long mx = strtoi(str);

        sort(str.begin(), str.end());
        int i; for (i=0; str[i]=='0'; ++i);
        swap(str[i], str[0]);
        long long mn = strtoi(str);

        cout << mx << " - " << mn << " = "
             << (mx - mn) << " = 9 * "
             << (mx-mn)/9 << endl;
    }
}
