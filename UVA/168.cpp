#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

bool candles[27];
int findNext(vector<int> &ad, int t) {
	for (int j=0; j<ad.size(); j++) {
		int v = ad[j];
		if (v!=t && !candles[v])
			return v;
	}
	return -1;
}


int main(){
	char line[1000];
	vector<int> adj[27];

	while(cin.getline(line, 1000) && line[0]!='#') {
		int k = 0;
		for (int i=0; line[i]; i++)
			if (line[i]!=' ' && line[i]!='\t')
				line[k++] = line[i];
		line[k]=0;
		if (k==0) continue;
		if (line[0]=='#')break;


		for (int i=0; i<27; i++) {
			adj[i].clear();
			candles[i] = false;
		}
		
		char m, t;
		for(char *token=strtok(line, ";"); token; token=strtok(0, ";.")) 
			if (token[1]) {
				if(token[1]==':') {
					int f = token[0]-'A';
					for(int i=2; token[i]; i++)
						if (token[i]>='A' && token[i]<='Z')
							adj[f].push_back(token[i]-'A');
				}
				else sscanf(token, " %c %c %d", &m, &t, &k);
			}
		m-='A'; 
		t-='A';


		bool done = false;
		while(true) {
			for (int i=0; i<k; i++) {
				int v = findNext(adj[m], t);
				if (v < 0) {
					cout << "/" << char('A' + m) << endl;
					done = true;
					break;
				}
				else {
					t = m;
					m = v;
				}
			}
			if (done) break;
			
			cout << char('A' + t) << " ";
			candles[t] = true;
		}
	}
}
