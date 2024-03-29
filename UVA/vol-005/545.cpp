/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 545
  Name: Heads
  Problem: https://onlinejudge.org/external/5/545.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace std;

int main(){
  register int n,nn,t2;
  register double t;
  scanf("%d",&nn);
  while(nn--){
    scanf("%d",&n);
    t=n*0.30102999566398;
    t2=t;
    printf("2^-%d = %.3fE-%d\n",n,pow(10.0,t2-t+1),t2+1);
  }
  return 0;
}