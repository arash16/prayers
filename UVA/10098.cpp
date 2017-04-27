#include <stdio.h>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

char str[15];
bool seen[15];
char perm[15];
void prec(int ind) {
	perm[ind] = 0;
	if (str[ind] == 0) {
		cout << perm << endl;
		return;
	}

	for (int i=0; str[i]; i++)
		if (!seen[i] && str[i] != perm[ind]) {
			seen[i] = true;
			perm[ind] = str[i];
			prec(ind + 1);
			seen[i] = false;
		}
}

int main() {
	int n;
	cin >> n;
	while (getchar() != '\n');
	while (n--) {
		memset(seen, 0, sizeof(seen));
		cin >> str;
		int l = strlen(str);
		sort(str, str + l);
		prec(0);
		cout << endl;
	}
}