#include <stdio.h>
#include <iostream>
using namespace std;


short DP[1000001];
int d[15];

int main(){
	int m,n,i,j;

	while(scanf("%d%d",&n,&m)==2){
		for(i=0;i<m;i++)
			cin>>d[i];

		DP[0]=0;
		for(i=1;i<n+1;i++){
			DP[i]=0;
			for(j=0;j<m;j++)
				if((i-d[j]>=0) && DP[i-d[j]]==0)
					DP[i]=1;
		}

		if(DP[n])
			puts("Stan wins");
		else
			puts("Ollie wins");
	}
}