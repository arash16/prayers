/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 536
  Name: Tree Recovery
  Problem: https://onlinejudge.org/external/5/536.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

char pre[30],in[30],l;
void post(int x,int y){
    int i,j,k=0,p=0,t=1;
    if(x>=y)return;

    for(i=0;i<l && t;i++)
        for(j=x;j<y && t;j++)
            if(pre[i]==in[j])
                k=i,
                p=j,
                t=0;

    post(x,p);
    post(p+1,y);
    printf("%c",pre[k]);
}


int main(){
    while(scanf("%s%s",pre,in)==2){
        l=strlen(pre);
        post(0,l);
        printf("\n");
    }
    return 0;
}