#include <stdio.h>
#include <cstring>
#include <iostream>
using namespace std;

#define MAXL 300
#define MAXN 105
char line[MAXN][MAXL];
bool seen[MAXN][MAXN];
int n, m;

int dfs(int x, int y) {
	if (x<0 || y<0 || x>=m || y>=n || seen[y][x] || line[y][x]!='W')
		return 0;
	
	seen[y][x] = 1;
	int sum=1;
	for (int i=-1; i<=1; i++)
		for (int j=-1; j<=1; j++)
			if (i || j)
				sum += dfs(x+i, y+j);

	return sum;
}


int main(){
	int T, x, y;
	cin>>T; 
	cin.getline(line[0], MAXL);
	cin.getline(line[0], MAXL);

	while (T--) {
		n=0;
		while (cin.getline(line[n], MAXL) && (line[n][0]=='L' || line[n][0]=='W'))
			n++;
		m = strlen(line[0]);

		while (line[n][0]) {
			for (int i=0; i<n; i++)
				for (int j=0; j<m; j++)
					seen[i][j] = 0;

			sscanf(line[n], "%d %d", &y, &x);
			cout << dfs(x-1, y-1) << endl;

			cin.getline(line[n], MAXL);
		}
		if (T) cout<<endl;
	}
}
