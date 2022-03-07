/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 948
  Name: Fibonaccimal Base
  Problem: https://onlinejudge.org/external/9/948.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

int Fib[43] = {1, 2};
int main() {
    for (int i=2; i<43; i++)
        Fib[i] = Fib[i-1] + Fib[i-2];

    int T, n;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        printf("%d = ", n);

        int lastI = -1;
        for (int x=n; x; ) {
            int ind = lower_bound(Fib, Fib+43, x) - Fib;
            if (Fib[ind] > x) --ind;
            for (int i=lastI-1; i>ind; i--)
                putchar('0');
            putchar('1');
            x -= Fib[lastI = ind];
        }
        for (; lastI>0; lastI--) putchar('0');
        puts(" (fib)");
    }
}
