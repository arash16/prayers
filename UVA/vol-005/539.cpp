/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 539
  Name: The Settlers of Catan
  Problem: https://onlinejudge.org/external/5/539.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
#include <cstring>
using namespace std;

int map[30][30];
int cover[30][30];
int maxdeph;
int n;

void dfs(int node,int deph){
    int i;

    for(i=0;i<n;i++)
        if(cover[node][i]==0 && map[node][i]){
            cover[node][i]=cover[i][node]=1;
            dfs(i,deph+1);
            cover[node][i]=cover[i][node]=0;
        }

    if(deph>maxdeph)
        maxdeph=deph;
}


int main(){
    int m,i,a,b;
    while(scanf("%d%d",&n,&m)==2 && m+n){
        memset(map,0,sizeof(map));
        memset(cover,0,sizeof(cover));
        maxdeph=0;
        for(i=0;i<m;i++){
            scanf("%d%d",&a,&b);
            map[a][b]=map[b][a]=1;
        }
        for(i=0;i<n;i++)
            dfs(i,0);
        cout<<maxdeph<<endl;

    }
}