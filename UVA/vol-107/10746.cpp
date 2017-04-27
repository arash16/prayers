#include <stdio.h>
#include <iostream>
#include <string.h>
#include <limits.h>
#include <math.h>
#include <cstring>
using namespace std;

#define CLR(a, x) memset( a, x, sizeof( a ) )
#define Inf (INT_MAX/2)
#define eps 1e-5
// the maximum number of vertices + 1
#define NN 1024
int cap[NN][NN];
double cost[NN][NN];
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
            if( fnet[v][u] && d[v] > Pot(u,v) - cost[v][u] - eps) 
                d[v] = Pot( u, v ) - cost[v][u] - eps, par[v] = -u-1;
            if( fnet[u][v] < cap[u][v] && d[v] > Pot(u,v) + cost[u][v] + eps) 
                d[v] = Pot(u,v) + cost[u][v] + eps, par[v] = -u - 1;
        }
    }
    for( int i = 0; i < n; i++ ) if( pi[i] < Inf ) pi[i] += d[i];
    return par[t] >= 0;
}
#undef Pot

int mcmf3( int n, int s, int t, double &fcost )
{
    CLR( deg, 0 );
    for( int i = 0; i < n; i++ )
    for( int j = 0; j < n; j++ ) 
        if( cap[i][j] || cap[j][i] ) adj[i][deg[i]++] = j;
    CLR( fnet, 0 );
    CLR( pi, 0 );
    int flow = fcost = 0;
    while( dijkstra( n, s, t ) ) 
    {
        int bot = INT_MAX;
        for( int v = t, u = par[v]; v != s; u = par[v = u] )
            bot = min(bot , fnet[v][u] ? fnet[v][u] : ( cap[u][v] - fnet[u][v] ));
        for( int v = t, u = par[v]; v != s; u = par[v = u] )
            if( fnet[v][u] ) { fnet[v][u] -= bot; fcost -= bot * cost[v][u]; }
            else { fnet[u][v] += bot; fcost += bot * cost[u][v]; }
        flow += bot;
    }
    return flow;
}



int main(){
	int n,m,i,j;
	double t;
	while(scanf("%d%d",&n,&m)==2 && n+m){
		memset(cap,0,sizeof(cap));
		for(i=0;i<n;i++)
			for(j=0;j<m;j++){
				scanf("%lf",&cost[i+2][n+j+2]);
				cap[i+2][n+j+2]=1;
			}
		for(i=2;i<n+2;i++)
			cap[0][i]=1;
		for(i=n+2;i<n+m+2;i++)
			cap[i][1]=1;

		mcmf3(n+m+2,0,1,t);
		printf("%.2lf\n",round(100*(double)t/n)/100.0);
	}
}