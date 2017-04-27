#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int comp(const string &a,const string &b){
	int i;
	for(i=0;i<min(a.length(),b.length()) && a[i]==b[i];i++);
	return i;
}

int main(){
	string list[100],str;
	string word,fw,lw;
	int nn,n,i,j,count,t,t2;
	scanf("%d",&nn);
	while(nn--){
		scanf("%d",&n);
		list[0]="";
		for(i=0;i<n;i++){
			cin>>word;
			list[i]=word;
		}
		count=list[0].length();
		for(i=1;i<n;i++){
			t=comp(list[i-1],list[i]);
			for(j=i+1;j<n;j++)
			{
				t2=comp(list[j],list[i-1]);
				if(t2>t){
					t=t2;
					str=list[i];
					list[i]=list[j];
					list[j]=str;
				}
			}
			count+=list[i].length()-t;
		}
		cout<<count<<endl;
		for(i=0;i<n;i++)
			cout<<list[i]<<endl;
	}
	return 0;
}