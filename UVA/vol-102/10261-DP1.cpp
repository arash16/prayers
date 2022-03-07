/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10261
  Name: Ferry Loading
  Problem: https://onlinejudge.org/external/102/10261.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
#include <map>
using namespace std;

#define MAXL 10001

char names[2][16] = { "port", "starboard" };
int X[10001], n;

map<int, map<int, map<int, int> > > memo, P;
int getMemo(int r1, int r2, int ind) {
    auto it1 = memo.find(r1);
    if (it1 != memo.end()) {
        auto it2 = it1->second.find(r2);
        if (it2 != it1->second.end()) {
            auto it3 = it2->second.find(ind);
            if (it3 != it2->second.end())
                return it3->second;
        }
    }
    return -1;
}


int maxCar(int r1, int r2, int ind) {
    if (ind == n) return 0;

    int res = getMemo(r1, r2, ind);
    if (res != -1) return res;

    int mx = 0;
    if (X[ind] <= r1) {
        mx = maxCar(r1-X[ind], r2, ind+1) + 1;
        P[r1][r2][ind] = 0;
    }

    if (X[ind] <= r2) {
        int t = maxCar(r1, r2-X[ind], ind+1) + 1;
        if (t > mx) {
            mx = t;
            P[r1][r2][ind] = 1;
        }
    }

    return memo[r1][r2][ind] = mx;
}


int main(){
    int T, len;
    cin>>T;
    while (T--) {
        cin >> len; len *= 100;

        int rs = 0;
        for (n=0; cin>>X[n] && X[n]; n++)
            if ((rs += X[n]) > 2*len)
                n--;

        memo.clear();
        int res = maxCar(len, len, 0);
        cout << res << endl;

        int r1=len, r2=len, ind=0;
        for (int i=0; i<res; i++) {
            cout << names[P[r1][r2][ind]] << endl;
            if (P[r1][r2][ind])
                r2 -= X[ind];
            else
                r1 -= X[ind];
            ind++;
        }

        if (T) putchar('\n');
    }
}
