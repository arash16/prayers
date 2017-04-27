#include <stdio.h>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

char chars[30], sels[30], seen[30];
int n, adj[27][27], ids[127];
vector<string> result;

void dfs(int u, int ind) {
	if (ind == n-1) {
		char w[] = "                                                                                ";
		for (int i=0; i<n-1; i++)
			w[2*i] = chars[sels[i]];
		w[2*n-3]=0;
		result.push_back(w);
		return;
	}

	seen[u] = 1;
	for (int v=1; v<n; v++)
		if (!seen[v]) {
			bool f = true;
			for (int j=0; f && j<ind; j++)
				if (adj[v][sels[j]])
					f = false;

			if (f) {
				sels[ind] = v;
				dfs(v, ind+1);
			}
		}
	seen[u] = 0;
}


int main(){
	char l1[100], l2[100], rel[100];
	int T;
	cin>>T;
	cin.getline(l1, 100);
	while (T--) {
		cin.getline(l1, 100);
		cin.getline(l1, 100); stringstream sin1(l1);
		cin.getline(l2, 100); stringstream sin2(l2);
		
		for (n=1; sin1>>chars[n]; n++)
			ids[chars[n]] = n;

		memset(adj, 0, sizeof(adj));
		while (sin2>>rel)
			adj[ids[rel[0]]][ids[rel[2]]]=1;

		result.clear();
		dfs(0, 0);
		if (result.size()) {
			sort(result.begin(), result.end());
			for (string s: result)
				cout << s << endl;
		}
		else puts("NO");
		if (T) cout << endl;
	}
}
