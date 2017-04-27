#include <bits/stdc++.h>
using namespace std;

list<int> adj[100];
bool inside[100];
int dfs(int u) {
	inside[u] = 1;
	int sum = 1;
	for (int v: adj[u])
		if (!inside[v])
			sum += dfs(v);
	inside[u] = 0;
	return sum;
}

int vn;
unordered_map<int, int> ids;
int getId(int x) {
	auto it = ids.find(x);
	if (it != ids.end())
		return it->second;
	
	adj[vn].clear();
	return ids[x] = vn++;
}


int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);

	for (int cse=1; ; ++cse) {
		ids.clear();
		int en=vn=0;
		bool ins[100]={}, ist=1;
		for (int u, v; cin>>u>>v && (u||v); ++en) {
			if (u<0 || v<0) return 0;
			if (u == v) ist=0;
			if (ist) {
				v = getId(v);
				if (ins[v]) ist = 0;
				else {
					ins[v] = 1;
					adj[getId(u)].push_back(v);
				}
			}
		}

		if (vn && en!=vn-1) ist = 0;
		for (int i=0; ist && i<vn; ++i)
			if (!ins[i] && dfs(i)!=vn)
				ist = 0;

		printf("Case %d is %s.\n", cse, ist ? "a tree": "not a tree");
	}
}
