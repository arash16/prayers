#include <stdio.h>
#include <iostream>
using namespace std;

int ids[50005];
int find(int i) {
	if (ids[i]==i) return i;
	return ids[i]=find(ids[i]);
}
void merge(int x, int y) {
	ids[find(x)]=ids[find(y)];
}

int main(){
	int cse=1, n, m, x, y;
	while(cin>>n>>m && (n||m)) {
		for (int i=0; i<n; i++)
			ids[i]=i;
		
		for (int i=0; i<m; i++) {
			cin>>x>>y;
			merge(x-1, y-1);
		}
		
		int cnt=0;
		for (int i=0; i<n; i++)
			if (ids[i]==i)
				cnt++;
		
		printf("Case %d: %d\n", cse++, cnt);
	}
}
