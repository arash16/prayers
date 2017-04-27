#include <stdio.h>
#include <iostream>
#include <stack>
#include <deque>
#include <cstring>
#define MAXINT 2147483647
#define MAX 202
using namespace std;


int par[MAX];
int cov[MAX];
int rcap[MAX];
int lcap[MAX][MAX];
int lflw[MAX][MAX];
int rflw[MAX];
int n;
deque<int> bfss;


int bfs(){
	int node,i,found=0,f;

	memset(cov,0,sizeof(cov));
	memset(par,0,sizeof(par));
	bfss.clear();
	bfss.push_back(0);
	while(!bfss.empty() && !found){
		node=bfss.front();
		bfss.pop_front();
		for(i=1;i<n && !found;i++)
			if(!cov[i] && lflw[node][i]<lcap[node][i]){
				cov[i]=1;
				par[i]=node;
				bfss.push_back(i);
				if(i==1)found=1;
			}
	}
	if(!found)return 0;
	f=MAXINT;
	for(i=1;i;i=par[i]){
		if(lcap[par[i]][i]-lflw[par[i]][i]<f)
			f=lcap[par[i]][i]-lflw[par[i]][i];
	}
	return f;
}


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
			lcap[0][2*c]=MAXINT;
		}

		for(i=0;i<b;i++){		//get sinks
			scanf("%d",&c);
			lcap[2*c+1][1]=MAXINT;
		}
		n=2*n+2;
		while(t=bfs()){
			for(i=1;i;i=par[i]){
				lflw[par[i]][i]+=t;
				lflw[i][par[i]]-=t;
			}
		}
		int sum=0;
		for(i=0;i<n;i++)
			sum+=lflw[0][i];
		printf("%d\n",sum);
	}

	return 0;
}