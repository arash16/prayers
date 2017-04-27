#include <stdio.h>
#include <iostream>
#include <functional>
#include <vector>
#include <queue>
using namespace std;

int main() {
	int T, m, n, u, X[40000];

	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &m, &n);
		for (int i=0; i<m; i++)
			scanf("%d", X+i);

		priority_queue<int> lq;
		priority_queue<int, vector<int>, greater<int> > rq;
		lq.push(X[0]);
		int j = 1;

		for (int i=0; i<n; ++i) {
			scanf("%d", &u);
			for(; j<u; ++j) {
				if (X[j] < lq.top()) {
					rq.push(lq.top());
					lq.push(X[j]);
					lq.pop();
				}
				else rq.push(X[j]);
			}
			printf("%d\n", lq.top());
			if (rq.empty())
				lq.push(X[j++]);
			else {
				lq.push(rq.top());
				rq.pop();
			}
		}

		if (T) putchar('\n');
	}
}
