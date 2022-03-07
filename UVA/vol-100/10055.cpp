/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10055
  Name: Hashmat the Brave Warrior
  Problem: https://onlinejudge.org/external/100/10055.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
    long long int x, y;
    while (cin>>x>>y)
        cout << (x<y?y-x:x-y)<<endl;
}
