/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10530
  Name: Guessing Game
  Problem: https://onlinejudge.org/external/105/10530.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
    char w1[10], w2[10];
    int x, mx=11, mn=0;

    while (cin>>x>>w1>>w2 && x) {
        if (w1[0]=='r') {
            if (x>mn && x<mx)
                cout << "Stan may be honest\n";
            else
                cout << "Stan is dishonest\n";

            mx=11, mn=0;
        }

        else if (w2[0] == 'l')
            mn = x>mn ? x : mn;
        else
            mx = x<mx ? x : mx;
    }
}
