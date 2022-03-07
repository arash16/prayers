/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10928
  Name: My Dear Neighbours
  Problem: https://onlinejudge.org/external/109/10928.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
using namespace std;

inline int readchar() {
    const int N = 1048576;
    static char buf[N];
    static char *p = buf, *end = buf;
    if(p == end) {
        if((end = buf + fread(buf, 1, N, stdin)) == buf) return EOF;
        p = buf;
    }
    return *p++;
}

int readCount() {
    int c = 0;
    char ch, lastCh = ' ';
    while ((ch = readchar()) != '\n' && ch>=0) {
        if (lastCh==' ' && ch!=' ')
            ++c;
        lastCh = ch;
    }
    return c;
}

bool isdigit(char ch) { return ch>='0' && ch<='9'; }
int readInt() {
    int r = 0;
    char ch;
    while (!isdigit(ch=readchar()));
    r = ch-'0';
    while (isdigit(ch=readchar()))
        r = r*10 + ch-'0';

    while (ch!='\n') ch=readchar();
    return r;
}



int A[2000];
int main(){
    int T, n, c;
    T = readInt();
    while (T--) {
        n = readInt();

        int mn=100000, c=0;
        for (int i=0; i<n; ++i) {
            int x = readCount();
            if (x < mn) {
                mn = x;
                c = 0;
            }
            if (x == mn)
                A[c++] = i+1;
        }
        printf("%d", A[0]);
        for (int i=1; i<c; ++i)
            printf(" %d", A[i]);
        putchar('\n');
    }
}
