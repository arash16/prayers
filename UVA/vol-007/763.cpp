#include <stdio.h>
#include <cstring>
#include <iostream>
using namespace std;

int n1[2000], n1l;
void inc(int ind) {
	if (ind >= n1l) {
		for (int i=n1l; i<=ind+1; i++)
			n1[i] = 0;
		n1l = ind+1;
	}

	if (!n1[ind]) {
		if (ind>0 && n1[ind-1]) {
			n1[ind-1] = 0;
			inc(ind + 1);
		}
		else if (n1[ind+1]) {
			n1[ind+1] = 0;
			inc(ind + 2);
		}
		else n1[ind] = 1;
	}
	else {
		if (!ind) {
			n1[0] = 0;
			inc(1);
		}
		else if (ind == 1) {
			n1[0] = 1;
			n1[1] = 0;
			inc(2);
		}
		else {
			inc(ind-1);
			inc(ind-2);
		}
	}
}

int main() {
	bool frst=1;
	char b1[1000], b2[1000];
	while (scanf("%s %s", b1, b2) == 2) {
		n1l = 1; n1[0]=n1[1]=0;
		int k=0;
		for (int i=strlen(b1)-1; i>=0; i--, k++)
			if (b1[i] == '1')
				inc(k);

		k=0;
		for (int i=strlen(b2)-1; i>=0; i--, k++)
			if (b2[i] == '1')
				inc(k);

		if (frst) frst = 0;
		else putchar('\n');
		for (int i=n1l-1; i>=0; i--)
			putchar(n1[i]+'0');
		putchar('\n');
	}
}
