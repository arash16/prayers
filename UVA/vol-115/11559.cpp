/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 11559
  Name: Event Planning
  Problem: https://onlinejudge.org/external/115/11559.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
    int n, b, h, w, p, beds;
    while(cin>>n>>b>>h>>w) {
        int bestp = 2147483647;
        for (int i=0; i<h; i++) {
            int f = false;
            cin >> p;
            for (int j=0; j<w; j++) {
                cin>>beds;
                if (beds>=n) f = true;
            }

            if (f && p<bestp)
                bestp = p;
        }

        if (bestp!=2147483647 && bestp*n<=b)
            cout << bestp*n << endl;
        else
            cout << "stay home\n";
    }
}
