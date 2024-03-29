/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 11879
  Name: Multiple of 17
  Problem: https://onlinejudge.org/external/118/11879.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
    char ch;
    for (;;) {
        int n = 0, i=0;
        while ((ch=getchar()) != '\n')
            n = (n*10 + ch - '0') % 17, i++;

        if (i==1 && !n) break;
        puts(n?"0":"1");
    }
}

