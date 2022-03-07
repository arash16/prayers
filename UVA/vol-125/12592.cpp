/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 12592
  Name: Slogan Learning of Princess
  Problem: https://onlinejudge.org/external/125/12592.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
#include <string>
#include <map>
using namespace std;

int main(){
    int n;
    while (scanf("%d", &n)==1) {
        string line, l2;
        getline(cin, line);
        map<string, string> mp;
        for (int i=0; i<n; i++) {
            getline(cin, line);
            getline(cin, l2);
            mp[line] = l2;
        }

        scanf("%d", &n);
        getline(cin, line);
        for (int i=0; i<n; i++) {
            getline(cin, line);
            cout << mp[line] << endl;
        }
    }
}
