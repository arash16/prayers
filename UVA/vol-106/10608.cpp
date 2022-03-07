/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10608
  Name: Friends
  Problem: https://onlinejudge.org/external/106/10608.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

vector<int> mp[30001];
int res[30001];
int count(int v) {
    if (res[v] != -1) return 0;

    res[v] = 1;
    for (auto w: mp[v])
        res[v] += count(w);

    return res[v];
}


int main(){
    int cse;
    cin>>cse;
    while(cse--) {
        int n, m;
        cin >> n >> m;
        for (int i=0; i<n; i++) {
            mp[i].clear();
            res[i] = -1;
        }

        for (int i=0; i<m; i++) {
            int a,b;
            cin>>a>>b;
            mp[a-1].push_back(b-1);
            mp[b-1].push_back(a-1);
        }

        int mx=0;
        for(int i=0; i<n; i++) {
            int r = count(i);
            if (r > mx) mx = r;
        }
        cout<<mx<<endl;
    }
}
