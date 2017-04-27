#include <stdio.h>
#include <iostream>
using namespace std;

bool seen[30];
bool ar[30][30];
int n;

int dfs (int v) {
	if (seen[v]) return 0;
	seen[v] = true;

	int res = 1;
	for (int i=0; i<n; i++)
		if (ar[i][v])
			res += dfs(i);
	
	return res;
}



int main(){
	char last, ed[30];
	int T;
	cin>>T;
	while(T--) {
		cin >> last;
		n = last - 'A' + 1;
		for (int i=0; i<n; i++) {
			seen[i] = 0;
			for (int j=i; j<n; j++)
				ar[i][j] = ar[j][i] = 0;
		}

		cin.getline(ed, 30);
		while (cin.getline(ed, 30) && ed[0])
			ar[ed[0]-'A'][ed[1]-'A'] = ar[ed[1]-'A'][ed[0]-'A'] = 1;
		
		int result = 0;
		for (int i=0; i<n; i++)
			result += dfs(i)>0;
		
		cout << result << endl;
		if (T) cout<<endl;
	}
}
