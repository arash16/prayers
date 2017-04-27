#include <stdio.h>
#include <iostream>
#include <map>
using namespace std;

map<int, map<int, int> > mp;
int main(){
	int n, u, v;
	while (cin>>n && n) {
		mp.clear();
		int cnt = 0;
		for (int i=0; i<n; i++) {
			cin>>u>>v;

			auto t = mp[v];
			if (t[u]>0) { t[u]--; cnt--; }
			else { mp[u][v]++; cnt++; }
		}

		puts(cnt ? "NO" : "YES");
	}
}
