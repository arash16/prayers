/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 869
  Name: Airline Comparison
  Problem: https://onlinejudge.org/external/8/869.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
#include <cstring>
using namespace std;

int f1[300][300],f2[300][300];

void check(){
    int i,j;
    for(i=0;i<256;i++)
        for(j=0;j<256;j++)
            if(f1[i][j]!=f2[i][j]){
                printf("NO\n");
                return;
            }
    printf("YES\n");
}

int main(){
    int nn,i,j,k,n;
    char src,dest;


    scanf("%d",&nn);
    while(nn--){
        memset(f1,0,sizeof(0));
        memset(f1,0,sizeof(0));
        scanf("%d\n",&n);
        for(i=0;i<n;i++){
            scanf("%c %c\n",&src,&dest);
            f1[src][dest]=1;
        }
        for(k=0;k<256;k++)
            for(i=0;i<256;i++)
                if(f1[i][k])
                    for(j=0;j<256;j++)
                        if(f1[k][j])
                            f1[i][j]=1;

        scanf("%d\n",&n);
        for(i=0;i<n;i++){
            scanf("%c %c\n",&src,&dest);
            f2[src][dest]=1;
        }
        for(k=0;k<256;k++)
            for(i=0;i<256;i++)
                if(f2[i][k])
                    for(j=0;j<256;j++)
                        if(f2[k][j])
                            f2[i][j]=1;

        check();
        if(nn)printf("\n");
    }
    return 0;
}