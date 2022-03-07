/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 11364
  Name: Parking
  Problem: https://onlinejudge.org/external/113/11364.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--) {
        int n, x, min=1000, max=-1000;
        cin>>n;
        while (n--) {
            cin>>x;
            if (x<min) min = x;
            if (x>max) max = x;
        }

        cout << 2*(max-min) <<endl;
    }
}
