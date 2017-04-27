#include <stdio.h>
#include <iostream>
#include <string>
#include <queue>
#include <list>
#include <map>
using namespace std;

#define INF 1073741824

bool issim(const char u[], const char v[]) {
	int i, cnt=0;
	for (i=0; cnt<2 && u[i] && v[i]; i++)
		if (u[i] != v[i])
			cnt++;

	if (u[i] != v[i])
		cnt++;
	
	return cnt<=1;
}


list<int> adj[202];
int d[202], n;
int bfs(int s, int t) {
	if (s==t) return 0;
	for (int i=0; i<n; i++)
		d[i]=INF;
	d[s]=0;

	queue<int> q;
	q.push(s); 
	while (!q.empty()) {
		int u=q.front(); q.pop();
		for (int v: adj[u])
			if (v == t) return d[u]+1;
			else if (d[v] > d[u]+1) {
				d[v] = d[u]+1;
				q.push(v);
			}
	}
	return -1;
}


int main(){
	char words[202][20], line[100], sw[20], tw[20];
	int T, s, t;
	cin>>T;
	while (T--) {
		map<string, int> ids;
		for (n=0; cin>>words[n] && words[n][0]!='*'; n++) {
			adj[n].clear();
			ids[words[n]] = n;
			for (int i=0; i<n; i++)
				if (issim(words[i], words[n])) {
					adj[i].push_back(n);
					adj[n].push_back(i);
				}
		}

		cin.getline(line, 20);
		while (cin.getline(line, 100) && line[0]) {
			sscanf(line, "%s %s", sw, tw);
			printf("%s %s %d\n", sw, tw, bfs(ids[sw], ids[tw]));
		}
		if (T) putchar('\n');
	}
}
