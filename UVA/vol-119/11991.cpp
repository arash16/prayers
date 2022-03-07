/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 11991
  Name: Easy Problem from Rujia Liu?
  Problem: https://onlinejudge.org/external/119/11991.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
using namespace std;


int main(){
    int n, m, x, k;
    while (cin>>n>>m) {
        map<int, vector<int> > pos;
        for (int i=1; i<=n; i++) {
            cin >> x;
            pos[x].push_back(i);
        }

        for (int i=0; i<m; i++) {
            cin >> k >> x;

            int r = 0;
            auto it = pos.find(x);
            if (it != pos.end()) {
                vector<int> &vv = it->second;
                if (vv.size() >= k)
                    r = vv[k-1];
            }
            cout << r << endl;
        }
    }
}
