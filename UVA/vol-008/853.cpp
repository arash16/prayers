#include <stdio.h>
#include <iostream>
#include <map>
#include <bitset>
#include <string>
#include <set>
#include <cstring>

using namespace std;

void toup(char* word){
	int i;
	for(i=0;word[i];i++)
		if(word[i]>='A' && word[i]<='Z')word[i]+=32;
}
typedef bitset<1001> biti;
int main(){
	int nn,n,i,j,s;
	char line[500],word[30],*p;
	map<string,biti>::iterator i1,i2;
	set<string>::iterator si;
	string ww;
	bool hw=0;
	scanf("%d",&nn);
	while(nn--){
		map<string,biti> l[2];
		scanf("%d",&n);getchar();
		for(j=0;j<2;j++)
			for(i=0;i<n;i++){
				gets(line);s=0;
				toup(line);
				while((line[s]<'a' || line[s]>'z') && line[s])s++;
				while(line[s] && sscanf(line+s,"%[abcdefghijklmnopqrstuvwxyz-]",word)==1){
					s+=strlen(word);
					while((line[s]<'a' || line[s]>'z') && line[s])s++;
					if(strlen(word)<3)continue;
					ww=word;
					l[j][ww].set(i);
				}
			}
		for(i1=l[0].begin();i1!=l[0].end();i1++)
		if(i1->second.count()>1){
			set<string> s1,s2;
			s1.insert(i1->first);
			for(i2=i1,i2++;i2!=l[0].end();i2++)
				if(i1->second==i2->second){
					s1.insert(i2->first);
					i2->second.reset();
				}
			for(i2=l[1].begin();i2!=l[1].end();i2++)
				if(i1->second==i2->second)
					s2.insert(i2->first);
			if(!s1.empty() && !s2.empty())
			{
				for(si=s1.begin();si!=s1.end();si++){
					if(si!=s1.begin())cout<<" ";cout<<*si;}
				cout<<"/";
				for(si=s2.begin();si!=s2.end();si++){
					if(si!=s2.begin())cout<<" ";cout<<*si;}
				cout<<"\n";
				hw=1;
			}
		}
		if(nn && hw)cout<<"\n";
		hw=0;
	}
	return 0;
}
