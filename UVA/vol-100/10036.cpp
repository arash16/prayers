#include <stdio.h>
#include <math.h>
#include <iostream>
using namespace std;


int d[10001],k,n;

int saved[10001][101];
bool smod(int ind,int m){
	if(m<0)m+=k;

	if(ind==n-1)
		return d[ind]%k==m;

	if(saved[ind][m]!=-1)return saved[ind][m];

	return saved[ind][m]=(	smod(ind+1,(m+d[ind]%k)%k)||
							smod(ind+1,m-d[ind]%k));
}

int main(){
	int T,i,j;
	cin>>T;
	while(T--){
		cin>>n>>k;
		for(i=0;i<n;i++){
			cin>>d[i];
			if(d[i]<0)d[i]=-d[i];
		}

		for(i=0;i<=n;i++)
			for(j=0;j<=k;j++)
				saved[i][j]=-1;

		if(smod(0,0))
			puts("Divisible");
		else
			puts("Not divisible");
	}
}