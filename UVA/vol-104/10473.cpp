/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10473
  Name: Simple Base Conversion
  Problem: https://onlinejudge.org/external/104/10473.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
using namespace std;
int main(){
    char str[20];
    long long int num;
    while(cin>>str && str[0]!='-')
        if (str[0]=='0' && str[1]=='x') {
            sscanf(str+2, "%llx", &num);
            printf("%lld\n", num);
        }
        else {
            sscanf(str, "%lld", &num);
            printf("0x%llX\n", num);
        }
}
