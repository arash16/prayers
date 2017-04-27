#include <stdio.h>
#include <iostream>
using namespace std;

bool canDefeat[200][200];
int main(){
	canDefeat['P']['R'] =
	canDefeat['R']['S'] =
	canDefeat['S']['P'] = 1;

	int T, n, m, r;
	char s1[101][101], s2[101][101];
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d%d", &n, &m, &r);
		for (int i=0; i<n; ++i) {
			while (getchar()!='\n');
			for (int j=0; j<m; ++j)
				s1[i][j] = getchar();
		}

		bool hasChange = 1;
		for (int k=0; hasChange && k<r; ++k) {
			hasChange = 0;
			for (int i=0; i<n; ++i)
				for (int j=0; j<m; j++) {
					char cur = s2[i][j] = s1[i][j];
					if (i && cur!=s1[i-1][j]) {
						hasChange = 1;
						if (canDefeat[cur][s1[i-1][j]])
							s2[i-1][j] = cur;
						else
							s2[i][j] = s1[i-1][j];
					}

					if (j && cur!=s1[i][j-1]) {
						hasChange = 1;
						if (canDefeat[cur][s1[i][j-1]])
							s2[i][j-1] = cur;
						else
							s2[i][j] = s1[i][j-1];
					}
				}

			swap(s1, s2);
		}

		for (int i=0; i<n; ++i) {
			for (int j=0; j<m; ++j)
				putchar(s1[i][j]);
			putchar('\n');
		}
		if (T) putchar('\n');
	}
}
