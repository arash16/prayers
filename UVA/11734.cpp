#include <stdio.h>
#include <iostream>
using namespace std;

char ww[3][30] = { "Wrong Answer", "Output Format Error", "Yes" },
	 jo[100], to[100];
int check() {
	int f=2, i,j;
	for (i=j=0; to[i] || jo[j]; i++)
		if (to[i]==' ' || to[i]=='\t') f = 1;
		else if (to[i] == jo[j]) j++;
		else return 0;

	return to[i] == jo[j] ? f : 0;
}

int main() {
	int T;
	cin>>T;
	cin.getline(jo, 100);
	for (int cse=1; cse<=T; cse++) {
		cin.getline(to, 100);
		cin.getline(jo, 100);
		printf("Case %d: %s\n", cse, ww[check()]);
	}
}
