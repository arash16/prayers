/*
  >>> ACM PROBLEM <<<

  ID: 443
  Name: Humble Numbers
  Author: Arash Shakery
  Email: arash.shakery@gmail.com
  Language: C++
*/

#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

void pnum(int cdnl){
    int test_c = abs(cdnl) % 10;
    cout<<cdnl;
    cout<<((abs(cdnl) %100 < 21 && abs(cdnl) %100 > 4) ? "th"
            : ((test_c < 4) ? (test_c < 3) ? (test_c < 2) ? (test_c < 1)
            ? "th" : "st" : "nd" : "rd" : "th"));
}

int h[]={2,3,5,7};
long long humble[5843];

int main()
{
  int i,j,k,n;
  long long t;
  humble[1]=1;
  for(i=2;i<5843;i++){
    humble[i]=2100000000;
    for(j=1;j<i;j++)
      for(k=0;k<4;k++)
        if((t=humble[j]*h[k])>humble[i-1] && t<humble[i])humble[i]=t;
  }

  while(cin>>n && n){
    printf("The ");pnum(n);printf(" humble number is %d.\n",humble[n]);
  }
  return 0;
}
