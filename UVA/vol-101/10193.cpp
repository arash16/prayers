/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10193
  Name: All You Need Is Love
  Problem: https://onlinejudge.org/external/101/10193.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
using namespace std;


int gcd(int a, int b) {
    if (b==0) return a;
    return gcd(b, a%b);
}

int convert(char *b) {
    int result = 0;
    for (int i=0; b[i]; i++) {
        result<<=1;
        if (b[i]=='1')
            result++;
    }
    return result;
}



int main() {
    char b1[40], b2[40];
    int T;
    cin>>T;
    for (int cse=1; cse<=T; cse++) {
        cin >> b1 >> b2;
        printf("Pair #%d: ", cse);
        if (gcd(convert(b1), convert(b2)) > 1)
            puts("All you need is love!");
        else
            puts("Love is not all you need!");
    }
}
