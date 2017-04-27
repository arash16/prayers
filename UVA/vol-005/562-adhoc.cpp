#include <stdio.h>
#include <cstring>
#include <iostream>
using namespace std;

int coins[102];

int memo[100002][102];
int rec(int diff, int i) {
	if (i<0) 
		return diff < 0 ? -diff : diff;

	if (memo[50000+diff][i] != -1)
		return memo[50000+diff][i];

	return memo[50000+diff][i] = min( rec(diff+coins[i], i-1), rec(diff-coins[i], i-1) );
}

int main(){
	int N;
	cin>>N;
	while(N--) {
		int m;
		cin>>m;
		for(int i=0; i<m; i++)
			cin>>coins[i];
		
		memset(memo, -1, sizeof(memo));
		cout << rec(0, m-1) << endl;
	}
}

