#include <stdio.h>
#include <iostream>
#include <functional>
#include <set>
using namespace std;

int main() {
	int T, m, n, u, X[40000];

	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &m, &n);
		for (int i=0; i<m; i++)
			scanf("%d", X+i);

		multiset<int> ss;
		ss.insert(X[0]);
		auto it = ss.begin();
		int j = 1;

		for (int i=0; i<n; ++i) {
			scanf("%d", &u);
			for(; j<u; ++j) {
				ss.insert(X[j]);
				if (X[j] < *it) --it;
			}
			printf("%d\n", *it);
			++it;
			if (it == ss.end()) {
				ss.insert(X[j++]);
				--it;
			}
		}

		if (T) putchar('\n');
	}
}
