#include <stdio.h>
#include <iostream>
#include <cstring>
using namespace std;

char s[1005];

//----------------------------------------------------------

int saved[1002][1002];
int rec(int i,int j){
	if(i>j)return 0;
	if(i==j)return 1;
	if(saved[i][j]!=-1)return saved[i][j];
	if(s[i]==s[j])return saved[i][j]=2+rec(i+1,j-1);
	return saved[i][j]=max(rec(i+1,j),rec(i,j-1));
}

//----------------------------------------------------------

int dp[1002][1002];
int f(register int n){
	register int i,j,l;

	for(l=1;l<n;l++)
		for(i=0;i<n-l;i++){
			j=i+l;
			if(s[i]==s[j])
				dp[i][j]=2+dp[i+1][j-1];
			else
				dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
		}

	return dp[0][n-1];
}

//----------------------------------------------------------

int main(){
	int T;

	register int i;
	for(i=0;i<1002;i++)
		dp[i][i]=1;

	cin>>T;
	gets(s); //better if always get input lines like this
	//there are problems with -->   scanf("%d\n");gets(s);
	while(T--){
		gets(s);
		cout<<f(strlen(s))<<endl;
	}
}