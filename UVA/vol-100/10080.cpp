#include <stdio.h>
#include <math.h>
#include <iostream>
#include <cstring>
#define MAXN 200
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



double g[MAXN][2];
double h[MAXN][2];
int flow[MAXN][MAXN];
int cap[MAXN][MAXN];

double dist(double x1,double x2,double y1,double y2){
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

int main(){
    int n,m,s,v,i,j,node;
    while(scanf("%d%d%d%d",&n,&m,&s,&v)==4){
        memset(cap,0,sizeof(cap));

        node=2;
        for(i=0;i<n;i++){
            scanf("%lf%lf",&g[i][0],&g[i][1]);
            cap[0][node++]=1;
        }

        for(i=0;i<m;i++){
            scanf("%lf%lf",&h[i][0],&h[i][1]);
            cap[node++][1]=1;
        }

        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
                if(dist(g[i][0],h[j][0],g[i][1],h[j][1])/v-s<1e-5)
                    cap[i+2][n+2+j]=1;

        printf("%d\n",n-max_flow(node,cap,0,1,flow));
    }
    return 0;
}