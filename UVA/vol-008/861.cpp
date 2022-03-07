/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 861
  Name: Little Bishops
  Problem: https://onlinejudge.org/external/8/861.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
#include <cstring>

using namespace std;

int a[20],n,k;

int too(int i){
    if(i<n)return i;
    else return 2*n-i;
}

int cross(int i,int j){
    return 2*a[i]+abs(n-i)==2*a[j]+abs(n-j) && a[i];
}

int check(int i){
    int j;
    for(j=i-2;j>0;j-=2)
        if(cross(j,i))
            return 0;
    return 1;
}

int rec(int u,int m){
    int i;
    int t;
    if(m==0)return 1;
    if(u>=2*n)return 0;

    a[u]=0;
    t=rec(u+2,m);
    for(i=1;i<=too(u);i++)
    {
        a[u]=i;
        if(check(u))
            t+=rec(u+2,m-1);
    }
    return t;
}

int s[9][3][65]={-1};
int saved(int i,int j){
    if(s[n][i][j]==-1)
        s[n][i][j]=rec(i,j);
    return s[n][i][j];
}


int ans(){
    int t=0;
    int i;
    for(i=0;i<=k;i++)
        t+=saved(1,i)*saved(2,k-i);
    return t;
}

int main(){
    memset(s,-1,sizeof(s));
    while(scanf("%d%d",&n,&k)==2 && n+k){
        cout<<ans()<<endl;
    }
}