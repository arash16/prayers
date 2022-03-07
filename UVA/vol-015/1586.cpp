/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 1586
  Name: Molar mass
  Problem: https://onlinejudge.org/external/15/1586.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int T;
    cin >> T;
    string str;
    while (T-- && cin>>str) {
        double sum = 0;
        for (int i=0; str[i]; ) {
            double m;
            switch (str[i++]) {
                case 'C': m=12.01; break;
                case 'H': m=1.008; break;
                case 'O': m=16.00; break;
                case 'N': m=14.01; break;
            }

            int q = 0;
            while (str[i]>='0' && str[i]<='9') {
                q = q*10 + str[i]-'0';
                ++i;
            }
            sum += (q==0 ? 1 : q) * m;
        }
        cout << fixed << setprecision(3) << sum << '\n';
    }
}
