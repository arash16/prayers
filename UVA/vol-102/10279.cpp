/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10279
  Name: Mine Sweeper
  Problem: https://onlinejudge.org/external/102/10279.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int T, n;
    cin >> T;
    while (T-- && cin>>n) {
        char B[17][17]={}, P[17][17]={};

        for (int i=1; i<=n; ++i)
            cin >> &B[i][1];

        bool boom = 0;
        for (int i=1; i<=n; ++i) {
            cin >> &P[i][1];
            for (int j=1; !boom && j<=n; ++j)
                if (P[i][j]=='x' && B[i][j]=='*')
                    boom = 1;
        }


        for (int i=1; i<=n; ++i) {
            for (int j=1; j<=n; ++j)
                if (boom && B[i][j]=='*')
                    cout << '*';
                else if (P[i][j] == '.')
                    cout << '.';
                else {
                    int sum=0;
                    for (int l=-1; l<2; ++l)
                        for (int r=-1; r<2; ++r)
                            sum += B[i+l][j+r] == '*';
                    cout << sum;
                }
            cout << '\n';
        }

        if (T) cout << endl;
    }
}
