#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <functional>
#include <string>
#include <queue>
#include <list>
#include <map>
using namespace std;

string names[110];
map<string, int> ids;

list<int> adj[110];
int ins[110], order[110];

int main(){
	int cse=1, n, m;
	string s1, s2;
	while (cin>>n) {
		for (int i=0; i<n; i++) {
			cin>>names[i];
			ids[names[i]] = i;
			adj[i].clear();
			ins[i] = 0;
		}
		
		cin>>m;
		for (int i=0; i<m; i++) {
			cin>>s1>>s2;
			adj[ids[s1]].push_back(ids[s2]);
			ins[ids[s2]]++;
		}
		

		priority_queue<int, vector<int>, greater<int> > q;
		for (int i=0; i<n; i++)
			if (!ins[i])
				q.push(i);

		int ocnt=0;
		while (!q.empty()) {
			int u = q.top(); q.pop();
			order[ocnt++] = u;
			for (int v: adj[u])
				if (--ins[v] == 0)
					q.push(v);
		}

		printf("Case #%d: Dilbert should drink beverages in this order:", cse++);
		for (int i=0; i<n; i++)
			cout << " " << names[order[i]];
		puts(".\n");
	}
}
