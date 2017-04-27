#include <bits/stdc++.h>
using namespace std;

int dn, pdep[10000], ord[10000];
char deps[20][200],
	title[10000][200],
	fname[10000][200],
	lname[10000][200],
	saddr[10000][500],
	hphon[10000][100],
	wphon[10000][100],
	cmail[10000][100],
	line[10000];

bool comp(int i, int j) { return strcmp(lname[i], lname[j]) < 0; }

int main() {
	while (scanf("%d", &dn) == 1) {
		int n = 0;
		gets(line);
		for (int i=0; i<dn; ++i) {
			for (gets(deps[i]); gets(line) && line[0]; ++n) {
				sscanf(line, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,]",
					title[n], fname[n], lname[n], saddr[n], hphon[n], wphon[n], cmail[n]);
				
				pdep[n] = i;
				ord[n] = n;
			}
		}


		sort(ord, ord+n, comp);
		for (int i=0; i<n; ++i) {
			int j = ord[i];
			puts("----------------------------------------");
			printf("%s %s %s\n%s\n", title[j], fname[j], lname[j], saddr[j]);
			printf("Department: %s\n", deps[pdep[j]]);
			printf("Home Phone: %s\n", hphon[j]);
			printf("Work Phone: %s\n", wphon[j]);
			printf("Campus Box: %s\n", cmail[j]);
		}
	}
}
