/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10806
  Name: Dijkstra, Dijkstra.
  Problem: https://onlinejudge.org/external/108/10806.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <iostream>
using namespace std;

#define Inf (INT_MAX/2)

// the maximum number of vertices + 1
#define NN 400
int cap[NN][NN];
int cost[NN][NN];
int fnet[NN][NN], adj[NN][NN], deg[NN];
int par[NN], d[NN];
int pi[NN];

#define Pot(u,v) (d[u] + pi[u] - pi[v])
bool dijkstra( int n, int s, int t )
{
    for( int i = 0; i < n; i++ ) d[i] = Inf, par[i] = -1;
    d[s] = 0;
    par[s] = -n - 1;
    while( 1 )
    {
        int u = -1, bestD = Inf;
        for( int i = 0; i < n; i++ ) if( par[i] < 0 && d[i] < bestD )
            bestD = d[u = i];
        if( bestD == Inf ) break;

        // relax edge (u,i) or (i,u) for all i;
        par[u] = -par[u] - 1;
        for( int i = 0; i < deg[u]; i++ )
        {
            int v = adj[u][i];
            if( par[v] >= 0 ) continue;
            if( fnet[v][u] && d[v] > Pot(u,v) - cost[v][u] )
                d[v] = Pot( u, v ) - cost[v][u], par[v] = -u-1;
            if( fnet[u][v] < cap[u][v] && d[v] > Pot(u,v) + cost[u][v] )
                d[v] = Pot(u,v) + cost[u][v], par[v] = -u - 1;
        }
    }
    for( int i = 0; i < n; i++ ) if( pi[i] < Inf ) pi[i] += d[i];
    return par[t] >= 0;
}
#undef Pot

int mcmf3( int n, int s, int t, int &fcost )
{
    int i,j;
    for(i=0;i<n;i++)deg[i]=pi[i]=0;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            fnet[i][j]=0;

    for(int i=0; i<n; i++)
    for(int j=0; j<n; j++)
        if( cap[i][j] || cap[j][i] ) adj[i][deg[i]++] = j;

    int flow=fcost=0;
    while(dijkstra(n,s,t)){
        int bot = INT_MAX;
        for(int v=t, u=par[v]; v!=s; u=par[v=u])
            bot = min(bot,fnet[v][u] ? fnet[v][u] : (cap[u][v]-fnet[u][v]));
        for(int v=t, u=par[v]; v!=s; u=par[v=u])
            if(fnet[v][u]) {fnet[v][u]-=bot; fcost-= bot*cost[v][u]; }
            else {fnet[u][v]+=bot; fcost+= bot*cost[u][v]; }
        flow+=bot;
    }
    return flow;
}


int main(){
    int n,m,a,b,c,f,i,j;
    while(scanf("%d",&n)==1 && n>0){
        scanf("%d",&m);
        for(i=0;i<m;i++){
            scanf("%d%d%d",&a,&b,&c);
            cap[a][b]=cap[b][a]=1;
            cost[a][b]=cost[b][a]=c;
        }
        cap[0][1]=2;
        if(mcmf3(n+1,0,n,f)>=2)
            printf("%d\n",f);
        else
            printf("Back to jail\n");


        for(i=0;i<=n;i++)
            for(j=0;j<=n;j++)
                cost[i][j]=cap[i][j]=0;
    }
}