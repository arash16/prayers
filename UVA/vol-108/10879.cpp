/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10879
  Name: Code Refactoring
  Problem: https://onlinejudge.org/external/108/10879.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <math.h>
#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
    int T, n, sq;
    cin>>T;
    for (int cse=1; cse<=T; cse++) {
        cin>>n;

        int x=n, f1=0, f2=0;
        for (int i=2; !f1 || !f2; i++)
            if (x%i==0) {
                if (!f1) f1 = i;
                else f2 = f1*i;
                x /= i--;
            }

        printf("Case #%d: %d = %d * %d = %d * %d\n", cse, n, f2, n/f2, f1, n/f1);
    }
}
