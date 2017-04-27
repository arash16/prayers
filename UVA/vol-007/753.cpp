#include <stdio.h>
#include <iostream>
#include <cstring>
using namespace std;


//Edmonds-Karp
//return the largest flow,flow[] will return every edge's flow
//n, the number of nodes in the graph;mat, the capacity matrix
//O(VE^2) 
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



char names[MAXN][MAXN];
int cap[MAXN][MAXN];
int flow[MAXN][MAXN];
int main(){
	int cse,i,j,n,m,k,s,t,en2,en1;
	scanf("%d",&cse);
	while(cse--){
		memset(cap,0,sizeof(cap));
		i=1;
		t=0;
		scanf("%d\n",&n);
		for(j=0;j<n;j++,i++){
			scanf("%s\n",names[i]);
			cap[i][t]=1;
		}

		s=i++;
		scanf("%d\n",&m);
		for(j=0;j<m;j++,i++){
			scanf("%*s %s\n",names[i]);
			cap[s][i]=1;
		}

		en1=i;
		scanf("%d\n",&k);
		for(j=0;j<k;j++,i++){
			scanf("%s %s\n",names[i],names[i+k]);
			cap[i][i+k]=inf;
		}

		en2=i+k;
		for(i=s+1;i<=s+m;i++)						//1
			for(j=1;j<=n;j++)						//4
				if(strcmp(names[i],names[j])==0)
					cap[i][j]=1;

		for(i=s+1;i<=s+m;i++)						//1
			for(j=en1;j<en1+k;j++)					//2
				if(strcmp(names[i],names[j])==0)
					cap[i][j]=inf;

		for(i=en1+k;i<en2;i++)						//3
			for(j=1;j<=n;j++)						//4
				if(strcmp(names[i],names[j])==0)
					cap[i][j]=1;

		for(i=en1+k;i<en2;i++)						//3
			for(j=en1;j<en1+k;j++)					//2
				if(strcmp(names[i],names[j])==0)
					cap[i][j]=inf;

		printf("%d\n",m-max_flow(en2,cap,s,t,flow));
		if(cse)printf("\n");
	}
	return 0;
}