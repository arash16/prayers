/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10082
  Name: WERTYU
  Problem: https://onlinejudge.org/external/100/10082.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <cstring>
#include <iostream>
using namespace std;

char lines[] = "`1234567890-=\tqwertyuiop[]\\asdfghjkl;'zxcvbnm,./~!@#$%^&*()_+QWERTYUIOP{}|ASDFGHJKL:\"ZXCVBNM<>?";
char m[256];
int main(){
    for(int i=1; lines[i]; i++)
        m[lines[i]]=toupper(lines[i-1]);

    char ch;
    while((ch=getchar())!=EOF)
        if (m[ch]) cout<<m[ch];
        else cout<<ch;
}
