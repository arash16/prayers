/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10633
  Name: Rare Easy Problem
  Problem: https://onlinejudge.org/external/106/10633.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    long long nm;
    while (cin>>nm && nm) {
        vector<long long> v;
        for (int i=0; i<10; i++)
            if ((nm-i)%9 == 0)
                v.push_back(10*((nm-i)/9) + i);

        if (!v.empty()) {
            sort(v.begin(), v.end());
            cout << v[0];
            for (int i=1; i<v.size(); i++)
                cout << " " << v[i];
        }
        cout << endl;
    }
}
