#include <stdio.h>
#include <cstring>
#include <iostream>
using namespace std;


bool ww[26];
bool lt[26][26];
void setLt(char *s1, char* s2) {
	int i;
	for (i=0; s1[i] && s1[i]==s2[i]; i++);
	if (s1[i] && s2[i] && s1[i]!=s2[i]) {
		lt[s1[i]-'A'][s2[i]-'A'] = true;
		ww[s1[i]-'A'] = ww[s2[i]-'A'] = 1;
	}
}


bool seen[26];
int order[26], oc;
void dfs(int v, bool root) {
	if (!seen[v]) {
		seen[v] = true;
		for (int i=0; i<26; i++)
			if (lt[v][i])
				dfs(i, 0);
		
		order[oc++] = v;
	}
}


int main(){
	char word[30], prev[30];
	while (cin>>prev) {
		memset(ww, 0, sizeof(ww));
		memset(lt, 0, sizeof(lt));
		memset(seen, 0, sizeof(seen));
		oc = 0;

		while (cin>>word && word[0]!='#') {
			setLt(prev, word);
			swap(prev, word);
		}

		for (int i=0; i<26; i++)
			if (ww[i])
				dfs(i, 1);


		for (int i=oc-1; i>=0; i--)
			cout<< (char)(order[i]+'A');
		cout<<endl;
	}
}
