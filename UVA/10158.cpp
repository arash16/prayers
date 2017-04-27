#include <stdio.h>
#include <iostream>
using namespace std;

bool isdigit(char ch) { return ch>='0' && ch<='9'; }
int readInt() {
	char ch;
	while (!isdigit(ch=getchar()));
	int r = ch-'0';
	while (isdigit(ch=getchar()))
		r = r*10 + ch-'0';
	return r;
}


#define MAXN 10017
short fid[MAXN], eid[MAXN], tmp[MAXN];
short findFid(short u) {
	if (u<0 || fid[u]==u) return u;

	int i=0;
	for (; u!=fid[u]; u=fid[u])
		tmp[i++] = u;

	for (int j=0; j<i; ++j)
		fid[tmp[j]] = u;

	return u;
}


bool areFriends(short u, short v) { return findFid(u) == findFid(v); }
bool areEnemies(short u, short v) { 
	if (u==-1 || v==-1 || u==v) return 0;
	short fu = findFid(u), eu = findFid(eid[fu]);
	if (eu < 0) return 0;
	short fv = findFid(v);
	return eu == fv || findFid(eid[fv]) == fu;
}

void setFriends(short u, short v) {
	if (u==-1 || v==-1 || u==v) return;
	if (areEnemies(u, v)) puts("-1");
	else {
		short fu = findFid(u), fv = findFid(v);
		if (fu != fv) {
			fid[fu] = fv;
			short eu = findFid(eid[fu]), ev = findFid(eid[fv]);
			if (ev < 0)
				eid[fv] = eu;
			else setFriends(eu, ev);
		}
	}
}

void setEnemies(short u, short v) {
	if (u==-1 || v==-1) return;
	short fu = findFid(u), fv = findFid(v);
	if (fu == fv) puts("-1");
	else {
		if (eid[fu]==-1) eid[fu] = fv;
		if (eid[fv]==-1) eid[fv] = fu;
		setFriends(eid[fu], fv);
		setFriends(eid[fv], fu);
	}
}


int main(){
	int n = readInt(), c, x, y;
	for (int i=0; i<n; ++i) {
		fid[i] = i;
		eid[i] = -1;
	}

	while ((c=readInt())) {
		int x = readInt(),
			y = readInt();
		switch (c) {
			case 1:
				setFriends(x, y);
				break;
			case 2:
				setEnemies(x, y);
				break;
			case 3:
				putchar('0' + areFriends(x, y));
				putchar('\n');
				break;
			case 4:
				putchar('0' + areEnemies(x, y));
				putchar('\n');
		}
	}
}
