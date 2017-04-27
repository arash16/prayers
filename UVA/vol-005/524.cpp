#include <stdio.h>
#include <math.h>
#include <iostream>
using namespace std;

int isprime(int x){
	int i;
	for(i=2;i<=sqrt((float)x);i++)
		if(x%i==0)
			return 0;
	return 1;
}
int isp[35],ans[17],n;

void rec(int j,int used){
	int i;
	if(j==n){
		if(!isp[ans[j-1]+1])return;
		for(i=0;i<n;i++){
			if(i)cout<<" ";
			cout<<ans[i];
		}
		cout<<endl;
		return;
	}

	for(i=1;i<=n;i++)
		if(!(used&(1<<i)) && isp[i+ans[j-1]]){
			ans[j]=i;
			rec(j+1,used | (1<<i));
		}
}

int main(){
	int i,cse=0;
	for(i=2;i<35;i++)
		isp[i]=isprime(i);

	ans[0]=1;
	while(scanf("%d",&n)==1){
		if(cse)cout<<endl;
		printf("Case %d:\n",++cse);
		rec(1,3);
	}
}