#include <stdio.h>
#include <iostream>
#include <queue>
using namespace std;

struct S {
	char url[105];
	int rel, ind;
	bool operator < (const S& o) const {
		return rel == o.rel ? ind > o.ind : rel < o.rel;
	}
};

int main(){
	int T;
	cin>>T;
	S sr;
	for (int cse=1; cse<=T; cse++) {
		priority_queue<S> p;
		for (int i=0; i<10; i++) {
			cin >> sr.url >> sr.rel;
			sr.ind = i;
			p.push(sr);
		}
		
		printf("Case #%d:\n", cse);
		int toprel = p.top().rel;
		while (p.top().rel == toprel) {
			cout << p.top().url << endl;
			p.pop();
		}
	}
}
