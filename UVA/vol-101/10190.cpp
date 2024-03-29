/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10190
  Name: Divide, But Not Quite Conquer!
  Problem: https://onlinejudge.org/external/101/10190.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
using namespace std;

int a[100000];
int main(){
    int t,n,m,i,k;
    while(scanf("%d%d",&n,&m)==2){
        t=n;
        for(i=0;n>1 && m!=1 && m!=0 && n%m==0;i++){
            n/=m;
            a[i]=n;
        }
        if(n!=1 || m==1 || !m || i<1)
            printf("Boring!\n");
        else{
            cout<<t;
            for(k=0;k<i;k++)
                printf(" %d",a[k]);
            cout<<endl;
        }
    }
}