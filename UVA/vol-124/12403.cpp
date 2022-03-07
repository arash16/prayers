/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 12403
  Name: Save Setu
  Problem: https://onlinejudge.org/external/124/12403.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
    char op[20];
    long long int n, x, s=0;
    cin>>n;
    while(n--) {
        cin>>op;
        if (op[0]=='r') cout<<s<<endl;
        else {
            cin>>x;
            s+=x;
        }
    }
}
