/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10361
  Name: Automatic Poetry
  Problem: https://onlinejudge.org/external/103/10361.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
#include <cstring>
#include <string>
#include <regex>
using namespace std;

int main(){
    regex r1("([^<]*)<([^>]*)>([^<]*)<([^>]*)>(.*)");
    regex r2("(.*)\\.\\.\\.$");
    char l1[1000], l2[1000];
    string ss[5];

    int n;
    cin >> n;
    cin.getline(l1, 1000);
    while (n--) {
        cin.getline(l1, 1000);
        cin.getline(l2, 1000);

        cmatch m;
        regex_match(l1, m, r1);
        for (int i=1; i<=5; i++)
            cout << (ss[i-1] = m[i]);
        cout<<endl;

        regex_match(l2, m, r2);
        cout << m[1] << ss[3] << ss[2] << ss[1] << ss[4] << endl;
    }
}
