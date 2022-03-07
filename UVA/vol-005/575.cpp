/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 575
  Name: Skew Binary
  Problem: https://onlinejudge.org/external/5/575.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
#include <cstring>
using namespace std;

int main(){
    int i,l,n;
    char num[100];
    while(gets(num) && (num[1] || num[0]=='1' || num[0]=='2')){
        l=strlen(num);
        for(n=i=0;num[i];i++)
            n+=((1<<(l-i))-1)*(num[i]-'0');
        cout<<n<<endl;
    }
}