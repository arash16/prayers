#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <set>
using namespace std;

set<char> nodes;
bool mat[200][200];

int bandwidth(char *s,int len){
	int l,i;
	for(l=len-1;l>=1;l--)
		for(i=0;i<len-l;i++)
			if(mat[s[i]][s[i+l]])
				return l;
	return 0;
}

int m;
char list[10],ans[10];
void permutation(int n,int i){
	if(i==n){
		int t=bandwidth(list,n);
		if(t<m){
			m=t;
			strcpy(ans,list);
		}
	}else{
		permutation(n,i+1);
		for(int j=i+1;j<n;j++){
			swap(list[i],list[j]);
			permutation(n,i+1);
			swap(list[i],list[j]);
		}
	}

}

int main(){
	char str[1000],*p;
	while(scanf("%s",str)==1 && strcmp(str,"#")!=0){
		nodes.clear();
		memset(mat,0,sizeof(mat));
		for(p=strtok(str,";");p;p=strtok(0,";")){
			int s=p[0],t;
			for(int i=2;t=p[i];i++){
				nodes.insert(s);
				nodes.insert(t);
				mat[s][t]=mat[t][s]=1;
			}
		}
		memset(list,0,sizeof(list));
		copy(nodes.begin(),nodes.end(),list);
		int l=strlen(list);
		m=100;
		permutation(l,0);

		for(int i=0;ans[i];i++)
			cout<<ans[i]<<" ";
		cout<<"-> "<<m<<endl;
	}
}