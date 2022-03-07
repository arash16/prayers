/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 290
  Name: Palindroms <---> smordnilaP
  Problem: https://onlinejudge.org/external/2/290.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <cstring>
#include <iostream>
using namespace std;


bool isPalin(const char str[], int l) {
    for (int i=l>>1; i>=0; --i)
        if (str[i] != str[l-i-1])
            return 0;
    return 1;
}

#define MAXL 10000
char s1[MAXL], s2[MAXL];

int numsteps(int base, const char str[], int len) {
    int l = len;
    memcpy(s1, str, l);
    for (int i=0; ; ++i) {
        if (isPalin(s1, l)) return i;

        int carry = 0;
        for (int i=0; i<l; ++i) {
            s2[i] = s1[i] + s1[l-i-1] + carry;
            carry = s2[i] / base;
            s2[i] %= base;
        }
        if (carry) s2[l++] = carry;
        swap(s1, s2);
    }
}

int main() {
    int l;
    char str[MAXL];
    while (scanf("%s", str)==1) {
        int mnb = 2;
        for (l=0; str[l]; l++) {
            str[l] = str[l]<60 ? str[l]-'0' : toupper(str[l])-55;
            mnb = max(mnb, str[l]+1);
        }

        printf("%d", numsteps(15, str, l));
        for (int i=14; i>=2; --i)
            if (i < mnb) printf(" ?");
            else printf(" %d", numsteps(i, str, l));
        putchar('\n');
    }
}
