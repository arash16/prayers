#include <stdio.h>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

struct Pilot {
	int tm;
	char name[30];
	bool operator < (const Pilot &o) const {
		if (tm != o.tm) return tm < o.tm;
		return strcasecmp(name, o.name) < 0;
	}
};

Pilot ps[200];

int main(){
	int n, mn, sc, ms;
	while (scanf("%d", &n)==1) {
		for (int i=0; i<n; i++) {
			scanf("%s : %d min %d sec %d ms", ps[i].name, &mn, &sc, &ms);
			ps[i].tm = mn*60000 + sc*1000 + ms;
		}

		sort(ps, ps+n);
		for (int i=0; i<n; ++i) {
			printf("Row %d\n", (i>>1)+1);
			printf("%s\n", ps[i].name);
			if (++i < n)
			printf("%s\n", ps[i].name);
		}
		putchar('\n');
	}
}
