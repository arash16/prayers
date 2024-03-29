/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 278
  Name: Chess
  Problem: https://onlinejudge.org/external/2/278.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
    int n, a, b;
    char c;
    cin>>n;
    while (n--) {
        cin>>c>>a>>b;
        if (a>b) swap(a, b);
        switch (c) {
            case 'r':
            case 'Q':
                cout << a << endl;
                break;
            case 'k':
                cout << ((a*b+1)>>1) << endl;
                break;
            case 'K':
                if (a&1) a++;
                if (b&1) b++;
                cout << (a*b>>2) << endl;
        }
    }
}
