#include <stdio.h>
#include <iostream>
#include <stack>
#include <deque>
#include <cstring>
using namespace std;


//Edmonds-Karp
//return the largest flow,flow[] will return every edge's flow
//n, the number of nodes in the graph;mat, the capacity matrix
//O(VE^2) 
#define MAXN 202
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

int par[MAXN];
int lcap[MAXN][MAXN];
int lflw[MAXN][MAXN];
int n;

int main(){
	int i,m,a,b,c,t,tt;
	while(scanf("%d",&n)==1){
		memset(lcap,0,sizeof(lcap));
		memset(lflw,0,sizeof(lflw));

		for(i=1;i<=n;i++){
			scanf("%d",&lcap[2*i][2*i+1]);
			lcap[2*i+1][2*i]=lcap[2*i][2*i+1];
		}

		scanf("%d",&m);			//get links capacities
		for(i=0;i<m;i++){
			scanf("%d%d%d",&a,&b,&c);
			lcap[2*a+1][2*b]+=c;
		}

		scanf("%d%d",&a,&b);
		for(i=0;i<a;i++){		//get sources
			scanf("%d",&c);
			lcap[0][2*c]=inf;
		}

		for(i=0;i<b;i++){		//get sinks
			scanf("%d",&c);
			lcap[2*c+1][1]=inf;
		}
		n=2*n+2;
		printf("%d\n",max_flow(n,lcap,0,1,lflw));
	}

	return 0;
}