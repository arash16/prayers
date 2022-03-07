/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 458
  Name: The Decoder
  Problem: https://onlinejudge.org/external/4/458.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
    char ch;
    while((ch=getchar())!=EOF)
        if (ch=='\n') cout<<endl;
        else cout<<char(ch-7);
}
