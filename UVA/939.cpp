#include <stdio.h>
#include <iostream>
#include <string>
#include <map>
using namespace std;

#define MAXN 3117
int states[MAXN], par1[MAXN], par2[MAXN];
char stateNames[3][50] = {
	"non-existent",
	"recessive",
	"dominant"
};

int lastId = 0;
string names[MAXN];
map<string, int> ids;
int readId() {
	cin>>names[lastId];
	auto it = ids.find(names[lastId]);
	if (it == ids.end()) {
		par1[lastId] = par2[lastId] = states[lastId] = -1;
		ids[names[lastId]] = lastId;
		return lastId++;
	}
	return it->second;
}

int newStates[] = { 0, 0, 1, 2, 2 };
int getState(int id) {
	if (states[id] != -1)
		return states[id];

	return states[id] = newStates[getState(par1[id]) + getState(par2[id])];
}

int main(){
	ids["dominant"] = -1;
	ids["recessive"] = -2;
	ids["non-existent"] = -3;

	int n;
	scanf("%d", &n);
	while (n--) {
		int x = readId(),
			y = readId();

		if (y < 0) 
			 states[x] = y+3;
		else if (par1[y]==-1) 
			 par1[y] = x;
		else par2[y] = x;
	}

	for (auto p: ids)
		if (p.second>=0)
			cout << p.first << ' ' << stateNames[getState(p.second)] << endl;
}
