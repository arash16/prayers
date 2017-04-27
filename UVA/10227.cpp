#include <stdio.h>
#include <iostream>
#include <bitset>
using namespace std;

bitset<101> bits[101];
int main(){
	char line[100];
	int T, n, m, i, j;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &m);
		for (int i=0; i<n; ++i)
			bits[i].reset();

		while (getchar()!='\n');
		while (cin.getline(line, 100) && line[0]) {
			sscanf(line, "%d%d", &i, &j);
			bits[i-1].set(j-1);
		}

		int cnt = 0;
		for (int i=0; i<n; ++i) {
			bool f = 1;
			for (int j=0; f && j<i; ++j)
				if (bits[j] == bits[i])
					f = 0;
			cnt += f;
		}
		
		printf("%d\n", cnt);
		if (T) putchar('\n');
	}
}
