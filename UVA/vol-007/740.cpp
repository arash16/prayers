/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 740
  Name: Baudot Data Communication Code
  Problem: https://onlinejudge.org/external/7/740.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    char sd[100], su[100];
    cin.getline(sd, 100);
    cin.getline(su, 100);

    string str;
    while (cin >> str) {
        char *ss = sd;

        for (int i=0; i<str.length(); i+=5) {
            int c = 0;
            for (int j=0; j<5; ++j)
                c = (c<<1) | (str[i+j] - '0');

            if (c == 31) ss = su;
            else if (c == 27) ss = sd;
            else cout << ss[c];
        }
        cout << endl;
    }
}
