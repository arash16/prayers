#include <stdio.h>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool see[6][26];
char row[20][20], res[6];
int sz[5];

int main(){
	int T, k;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &k);
		for (int i=0; i<12; i++)
			scanf("%s", row[i]);

		memset(see, 0, sizeof(see));
		for (int i=0; i<6; i++)
			for (int j=0; j<5; j++)
				see[j][row[i][j]-'A'] = 1;

		vector<char> ves[5];
		for (int j=4; j>=0; j--) {
			for (int i=6; i<12; i++)
				if (see[j][row[i][j]-'A']) {
					ves[j].push_back(row[i][j]);
					see[j][row[i][j]-'A'] = 0;
				}
			sort(ves[j].begin(), ves[j].end());
			sz[j] = j<4 ? sz[j+1]*ves[j+1].size() : 1;
		}

		if (sz[0]*ves[0].size() < k--) puts("NO");
		else {
			for (int j=0; j<5; j++) {
				int i = 0;
				while (sz[j]*(i+1) <= k) i++;
				res[j] = ves[j][i];
				k -= sz[j]*i;
			}
			puts(res);
		}
	}
}
