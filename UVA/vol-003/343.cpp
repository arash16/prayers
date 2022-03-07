/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 343
  Name: What Base Is This?
  Problem: https://onlinejudge.org/external/3/343.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
using namespace std;

int val[127];
const long long mask = (1LL<<55)-1;
long long conv(const char num[], const int bf) {
    long long result = 0;
    for (int i=0; num[i]; i++)
        result = (result*bf + val[num[i]]) &mask;
    return result;
}

int minbase(const char num[]) {
    int mn = 2;
    for (int i=0; num[i]; i++)
        if (val[num[i]] >= mn)
            mn = val[num[i]]+1;
    return mn;
}


int main(){
    char ds[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (int i=0; ds[i]; i++)
        val[ds[i]] = i;

    long long res[37];
    char w1[20000], w2[20000];
    while (cin>>w1>>w2) {
        int m1 = minbase(w1),
            m2 = minbase(w2);

        bool found = false;
        for (int i=m1; !found && i<=36; i++) {
            long long x = conv(w1, i);

            int lo=m2, hi=36, mid;
            while (lo<=hi) {
                mid = (lo+hi)>>1;
                res[mid] = conv(w2, mid);
                if (res[mid] < x) lo = mid+1;
                else hi = mid-1;
            }

            if (res[hi+1] == x) {
                printf("%s (base %d) = %s (base %d)\n", w1, i, w2, hi+1);
                found = true;
            }
        }

        if (!found)
            printf("%s is not equal to %s in any base 2..36\n", w1, w2);
    }
}
