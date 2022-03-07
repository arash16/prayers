/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10491
  Name: Cows and Cars
  Problem: https://onlinejudge.org/external/104/10491.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
    double c,w,s;
    while (cin>>w>>c>>s) {
        double sum=c+w;
        printf("%.5f\n", c*(sum-1)/(sum*(sum-s-1)));
    }
}
