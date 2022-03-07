/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 12032
  Name: The Monkey and the Oiled Bamboo
  Problem: https://onlinejudge.org/external/120/12032.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
using namespace std;

#define INF 1073741824
int x[100002], n;
bool ispos(int k) {
    for (int i=1; i<=n; i++) {
        int diff = x[i]-x[i-1];
        if (diff > k) return 0;
        if (diff == k) k--;
    }
    return 1;
}

int main() {
    int T;
    scanf("%d", &T);
    for (int cse=1; cse<=T; cse++) {
        scanf("%d", &n);
        int lo=0, hi=0;
        for (int i=1; i<=n; i++) {
            scanf("%d", x+i);
            int dif = x[i] - x[i-1];
            if (dif > lo)
                hi = lo = dif;
            else if (dif == lo)
                hi++;
        }

        while (lo <= hi) {
            int mid = (lo+hi)>>1;
            if (ispos(mid))
                hi = mid-1;
            else
                lo = mid+1;
        }
        printf("Case %d: %d\n", cse, hi+1);
    }
}
