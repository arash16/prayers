#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
using namespace std;


int main(){
	int n, m, x, k;
	while (cin>>n>>m) {
		map<int, vector<int> > pos;
		for (int i=1; i<=n; i++) {
			cin >> x;
			pos[x].push_back(i);
		}
	
		for (int i=0; i<m; i++) {
			cin >> k >> x;
		
			int r = 0;
			auto it = pos.find(x);
			if (it != pos.end()) {
				vector<int> &vv = it->second;
				if (vv.size() >= k)
					r = vv[k-1];
			}
			cout << r << endl;
		}
	}
}
