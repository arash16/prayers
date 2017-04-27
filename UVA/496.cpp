#include <stdio.h>
#include <cstring>
#include <iostream>
#include <bitset>
#include <map>
using namespace std;

#define MAXL 10000

int cnt;
map<int, int> ids;
int getId(int x) {
	int res = ids[x];
	if (!res) res = ids[x] = ++cnt;
	return res;
}

int main(){
	int x;
	char l1[MAXL], l2[MAXL];
	while (cin.getline(l1, MAXL) && cin.getline(l2, MAXL)) {
		bitset<128> b1, b2, c;
		ids.clear();
		cnt=0;

		for (char *p=strtok(l1," ");p;p=strtok(0," ")) {
			sscanf(p, "%d", &x);
			b1.set(getId(x));
		}

		for (char *p=strtok(l2," ");p;p=strtok(0," ")) {
			sscanf(p, "%d", &x);
			b2.set(getId(x));
		}

		if (b1 == b2)
			puts("A equals B");

		else {
			c = b1&b2;
			if (c == b1)
				puts("A is a proper subset of B");
			else if (c == b2)
				puts("B is a proper subset of A");
			else if (!c.count())
				puts("A and B are disjoint");
			else
				puts("I'm confused!");
		}
	}
}
