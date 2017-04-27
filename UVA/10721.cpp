#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
	long long DP[60];
	int N,K,M,n,k,i;

	while(scanf("%d%d%d",&N,&K,&M)==3)
	{
		DP[0]=1;
		for(n=1;n<=N;n++)
			DP[n]=0;

		for(k=1;k<=K;k++)
			for(n=N;n>=0;n--)
			{
				DP[n]=0;
				for(i=1;i<=min(n,M);i++)
					DP[n]+=DP[n-i];
			}


		cout<<DP[N]<<endl;
	}
}