#include <stdio.h>
#include <iostream>
using namespace std;


int DP[6002][1001],W[1001],L[1001];
int main(){
	int n,i,l;
	while(scanf("%d",&n)==1 && n!=0)
	{
		for(i=0;i<n;i++)
			scanf("%d%d",&W[i],&L[i]);

		for(l=0;l<6002;l++)
			DP[l][n]=0;

		for(i=n-1;i>=0;i--)
			for(l=0;l<6002;l++){
				DP[l][i]=DP[l][i+1];
				if(l-W[i]>=0 && L[i]>=0)
					DP[l][i]=max(DP[l][i],1+DP[min(L[i],l-W[i])][i+1]);
			}
		cout<<DP[6001][0]<<endl;
	}
}