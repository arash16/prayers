#include <stdio.h>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define MAXL 100000

struct Num {
	int ind;
	char x[50];
	bool operator < (const Num& o) const {
		return ind < o.ind;
	}
};

Num X[10000];

int main(){
	char line[MAXL];
	int T;
	cin>>T;
	while (T--) {
		cin.getline(line, MAXL);
		cin.getline(line, MAXL);
		cin.getline(line, MAXL);
		
		int cnt=0;
		for (char *p=strtok(line, " "); p; p=strtok(0, " "))
			sscanf(p, "%d", &X[cnt++].ind);
		for (int i=0; i<cnt; i++)
			cin>>X[i].x;

		sort(X, X+cnt);
		for (int i=0; i<cnt; i++)
			cout << X[i].x << endl;
		if (T) cout << endl;
	}
}
