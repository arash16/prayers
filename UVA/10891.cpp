#include <stdio.h>
#include <iostream>
using namespace std;

int d[105],s[105];
int DP[105][105];
int values(int x,int y){
	return s[y]-s[x-1];
}
int main(){
	int n,i,j,k;

	while(scanf("%d",&n)==1 && n)
	{
		for(i=1;i<=n;i++){
			cin>>d[i];
			s[i]=s[i-1]+d[i];
		}

		for(j=1;j<=n;j++)
			for(i=j;i>0;i--){
				DP[i][j]=-100000000;
				for(k=0;k<=j-i;k++)
					DP[i][j]=max(DP[i][j],max(
							values(i,i+k)-DP[i+k+1][j],
							values(j-k,j)-DP[i][j-k-1]));
			}

		cout<<DP[1][n]<<endl;

	}
}