#include <stdio.h>
#include <iostream>
#include <cstring>
using namespace std;
#define MAXN 100
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

int flow[MAXN][MAXN];
int cap[MAXN][MAXN];

int size(char *s){
	if(strcmp(s,"XXL")==0)
		return 1;
	else if(strcmp(s,"XL")==0)
		return 2;
	else if(strcmp(s,"L")==0)
		return 3;
	else if(strcmp(s,"M")==0)
		return 4;
	else if(strcmp(s,"S")==0)
		return 5;
	else if(strcmp(s,"XS")==0)
		return 6;
}

int main(){
	int cse,n,m,node,i;
	char s1[5],s2[5];

	scanf("%d",&cse);
	while(cse--){
		memset(cap,0,sizeof(cap));

		scanf("%d%d",&n,&m);
		for(i=1;i<=6;i++)
			cap[0][i]=n/6;
		node=8;
		for(i=0;i<m;i++){
			scanf("%s %s\n",&s1,&s2);
			cap[size(s1)][node]=1;
			cap[size(s2)][node]=1;
			cap[node][7]=1;
			node++;
		}
		printf(max_flow(node,cap,0,7,flow)==m?"YES\n":"NO\n");
	}
	return 0;
}