/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 11934
  Name: Magic Formula
  Problem: https://onlinejudge.org/external/119/11934.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
    int a,b,c,d,l;
    while (cin>>a>>b>>c>>d>>l && (a||b||c||d||l)) {
        a%=d;
        b%=d;
        c%=d;
        int cnt=0;
        for (int i=0; i<=l; i++)
            if ( ((((a*i)%d)*i)%d + (b*i)%d + c)%d ==0)
                cnt++;

        cout << cnt << endl;
    }
}
