/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10779
  Name: Collectors Problem
  Problem: https://onlinejudge.org/external/107/10779.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
#include <cstring>
using namespace std;

#define MAXN 1000
#define inf 1000000000

int max_flow(int n,int mat[][MAXN],int source,int sink,int flow[][MAXN]){
    int pre[MAXN],que[MAXN],d[MAXN],p,q,t,i,j;
    if (source==sink) return inf;
    for (i=0;i<n;i++)
        for (j=0;j<n;flow[i][j++]=0);
    while (true){
        for (i=0;i<n;pre[i++]=0);
        pre[t=source]=source+1,d[t]=inf;
        for (p=q=0;p<=q&&!pre[sink];t=que[p++])
            for (i=0;i<n;i++)
                if (!pre[i]&&(j=mat[t][i]-flow[t][i]))
                    pre[que[q++]=i]=t+1,d[i]=d[t]<j?d[t]:j;
                else if (!pre[i]&&(j=flow[i][t]))
                    pre[que[q++]=i]=-t-1,d[i]=d[t]<j?d[t]:j;
        if (!pre[sink]) break;
        for (i=sink;i!=source;)
            if (pre[i]>0)
                flow[pre[i]-1][i]+=d[sink],i=pre[i]-1;
            else
                flow[i][-pre[i]-1]-=d[sink],i=-pre[i]-1;
    }
    for (j=i=0;i<n;j+=flow[source][i++]);
    return j;
}


int cap[MAXN][MAXN];
int flow[MAXN][MAXN];

int main(){
    int T,cse,i,j,s,t,node,a,b,m,n;
    scanf("%d",&T);
    for(cse=1;cse<=T;cse++){
        memset(cap,0,sizeof(cap));
        scanf("%d%d",&n,&m);
        s=0;t=m+1;
        for(i=1;i<=m;i++)
            cap[i][t]=1;
        node=m+2;

        scanf("%d",&a);                    //bob hand
        for(i=0;i<a;i++){
            scanf("%d",&b);
            cap[s][b]++;
        }

        for(i=1;i<n;i++){
            scanf("%d",&a);
            for(j=0;j<a;j++){
                scanf("%d",&b);
                cap[node][b]++;
            }
            for(j=1;j<=m;j++)            //stick he need
                if(cap[node][j]==0)
                    cap[j][node]=1;

            for(j=1;j<=m;j++)            //sticks he doesnt need
                if(cap[node][j]<2)
                    cap[node][j]=0;
                else cap[node][j]--;
            node++;
        }
        printf("Case #%d: %d\n",cse,max_flow(node,cap,s,t,flow));
    }
}