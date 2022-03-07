/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 1260
  Name: Sales
  Problem: https://onlinejudge.org/external/12/1260.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
#include <cstring>
using namespace std;

unsigned short BIT[5001];

int getSum(int i) {
    int sum = 0; i++;
    while (i) {
        sum += BIT[i];
        i -= i & -i;
    }
    return sum;
}

int getRange(int i, int j) {
    i++; j++;
    int sum = 0;
    while (j > i) {
        sum += BIT[j];
        j -= j & -j;
    }
    while (i > j) {
        sum -= BIT[i];
        i -= i & -i;
    }
    return sum;
}

void update(int i, int val) {
    i++;
    while (i <= 5000) {
        BIT[i] += val;
        i += i & -i;
    }
}


int main(){
    int T, n, x;
    scanf("%d", &T);
    while (T--) {
        memset(BIT, 0, sizeof(BIT));
        int result = 0;
        scanf("%d", &n);
        for (int i=0; i<n; i++) {
            scanf("%d", &x);
            result += getSum(x);
            update(x, 1);
        }

        printf("%d\n", result);
    }
}
