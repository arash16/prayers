/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 147
  Name: Dollars
  Problem: https://onlinejudge.org/external/1/147.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <math.h>
#include <iostream>
using namespace std;


long long int ans[30001][11];
int main(){
    int coins[11]={10000,5000,2000,1000,500,200,100,50,20,10,5};
    int i,j,k;
    for(i=0;i<11;i++)
        ans[0][i]=1;

    for(i=1;i<30001;i++)
        for(k=0;k<11;k++){
            ans[i][k]=0;
            for(j=0;j<=k;j++)
                if(coins[j]<=i)
                    ans[i][k]+=ans[i-coins[j]][j];
        }

    double money;
    while(scanf("%lf",&money)==1 && money>0)
        printf("%6.2f%17lld\n",money,ans[(int)round(money*100)][10]);
}