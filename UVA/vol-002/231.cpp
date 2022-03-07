/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 231
  Name: Testing the CATCHER
  Problem: https://onlinejudge.org/external/2/231.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
using namespace std;

int main() {
    int M[1000000], X[1000000], cnt;
    for (int cse=1;;cse++) {
        for (cnt=0; ;cnt++) {
            M[cnt] = 0;
            cin>>X[cnt];
            if (X[cnt] < 0) break;
        }
        if (!cnt) break;
        if (cse>1) cout << endl;

        int l=0;
        for (int i=0; i<cnt; i++) {
            int lo=1, hi=l;
            while (lo<=hi) {
                int mid = (lo+hi+1)>>1;
                if (X[M[mid]] >= X[i])
                    lo = mid+1;
                else
                    hi = mid-1;
            }

            M[lo] = i;
            if (lo > l) l = lo;
        }

        printf("Test #%d:\n  maximum possible interceptions: %d\n", cse, l);
    }
}
