/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10041
  Name: Vito's Family
  Problem: https://onlinejudge.org/external/100/10041.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

int a[506];
int main(){
    int n,T,s,i;
    cin>>T;
    while(T--){
        cin>>n;
        for(i=0;i<n;i++)
            cin>>a[i];
        sort(a,a+n);
        s=0;
        for(i=0;i<n;i++)
            s+=abs(a[i]-a[n/2]);
        cout<<s<<endl;
    }
}