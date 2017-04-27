#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
	char s[1000],t[1000];
	int i,k=0;
	while(gets(s)){
		for(i=0;s[i];i++)
			if(s[i]!=' ')
				t[k++]=s[i];
			else{
				while(k--)cout<<t[k];
				cout<<s[i];
				k=0;
			}
		while(k--)cout<<t[k];
		cout<<endl;
		k=0;
	}
}