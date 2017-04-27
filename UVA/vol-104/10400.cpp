#include <stdio.h>
#include <iostream>
#include <cstring>
using namespace std;

int t,n,A[101];
char P[64009][101];
bool f(int b,int i){
	if(b<-32000 || b>32000)return false;
	if(i==n)
		if(b==t)
			return true;
		else
			return false;

	char &ans=P[b+32000][i];
	if(ans==-1){
		if(f(b+A[i],i+1))
			ans='+';
		else if(f(b-A[i],i+1))
			ans='-';
		else if(f(b*A[i],i+1))
			ans='*';
		else if(b%A[i]==0 && f(b/A[i],i+1))
			ans='/';
		else
			ans=0;
	}
	return ans;
}

int main(){
	int T,i,b;
	cin>>T;
	while(T--){
		cin>>n;
		for(i=0;i<n;i++)
			cin>>A[i];
		cin>>t;
		memset(P,-1,sizeof(P));
		if(f(A[0],1)){
			cout<<A[0];
			b=A[0];
			for(i=1;i<n;i++){
				cout<<P[b+32000][i];
				if(P[b+32000][i]=='+')
					b+=A[i];
				else if(P[b+32000][i]=='-')
					b-=A[i];
				else if(P[b+32000][i]=='*')
					b*=A[i];
				else if(P[b+32000][i]=='/')
					b/=A[i];
				cout<<A[i];
			}
			printf("=%d\n",t);
		}
		else
			cout<<"NO EXPRESSION\n";
	}
}
