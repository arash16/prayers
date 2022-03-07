/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 834
  Name: Continued Fractions
  Problem: https://onlinejudge.org/external/8/834.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
    int a, b;
    while(cin>>a>>b) {
        cout<<"[";
        for (int i=0; a && b; i++) {
            int x = a/b;
            int t = b;
            b = a - b*x;
            a = t;

            if (i==1) cout << ";";
            else if (i>1) cout << ",";
            cout << x;
        }
        cout << "]\n";
    }
}
