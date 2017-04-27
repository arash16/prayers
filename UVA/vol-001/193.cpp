#include <stdio.h>
#include <iostream>
#include <bitset>
using namespace std;

#define MAX_NODE 105
typedef bitset<MAX_NODE> biti;
int mat[MAX_NODE][MAX_NODE];
int n;

int deg(int node,biti set){
	int i,deg=0;
	for(i=1;i<=n;i++)
		if(set[i] && mat[node][i])
			deg++;
	return deg;
}

int select_node(biti set,int &mnode){
	int i,max=0,t;
	for(i=1;i<=n;i++)
		if(set[i] && (t=deg(i,set))>max){
			max=t;
			mnode=i;
		}
	return max;
}
biti rec(biti set){
	int mnode,i,d;
	d=select_node(set,mnode);
	if(d==0)return set;
	biti b1,b2;

	set.reset(mnode);
	b1=rec(set);

	for(i=1;i<=n;i++)
		if(mat[mnode][i])
			set.reset(i);
	b2=rec(set);
	b2.set(mnode);

	if(b1.count()>b2.count())
		return b1;
	else
		return b2;
}


int main(){
	int cse,k,i,j,a,b,sum;
	biti ans;
	cin>>cse;
	while(cse--){
		scanf("%d%d",&n,&k);

		for(i=0;i<k;i++){
			scanf("%d%d",&a,&b);
			mat[a][b]=mat[b][a]=1;
		}

		ans.set();
		ans=rec(ans);
		sum=0;
		for(i=1;i<=n;i++)
			if(ans[i])
				sum++;
		cout<<sum<<endl;a=0;
		for(i=1;i<=n;i++)
			if(ans[i]){
				if(a)cout<<" ";a=1;
				cout<<i;
			}
		cout<<endl;
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				mat[i][j]=0;

	}
}