#include <stdio.h>
#include <iostream>
#include <string>
#include <map>
using namespace std;

#define MAXN 100001

int ids[MAXN], sze[MAXN];
int find(int id) {
	return ids[id] == id ? id : (ids[id] = find(ids[id]));
}
int join(int u, int v) {
	u = find(u); v = find(v);
	if (u != v) {
		sze[v] += sze[u];
		ids[u] = v;
	}
	return sze[v];
}

int cnt;
map<string, int> names;
int find(string name) {
	auto it = names.find(name);
	if (it != names.end())
		return find(it->second);
	
	sze[++cnt] = 1;
	names[name] = cnt;
	return ids[cnt] = cnt;
}


int main(){
	string s1, s2;
	int T, n;
	cin>>T;
	while (T--) {
		names.clear(); cnt=0;
		cin >> n;
		for (int i=0; i<n; i++) {
			cin>>s1>>s2;
			cout << join(find(s1), find(s2)) << endl;
		}
	}
}
