/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10300
  Name: Ecological Premium
  Problem: https://onlinejudge.org/external/103/10300.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        long long int sum=0;
        while(n--) {
            int sz, an, fr;
            cin>>sz>>an>>fr;
            sum += sz*fr;
        }
        cout<<sum<<endl;
    }
}
