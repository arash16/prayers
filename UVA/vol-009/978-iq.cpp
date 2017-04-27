#include <stdio.h>
#include <cstring>
#include <iostream>
using namespace std;

class IndexedQueue {
	int *mems, gt, csz;
	public:
		IndexedQueue(int sz=101) {
			csz = 0;
			gt = -1;
			mems = new int[sz];
			memset(mems, 0, sz * sizeof(int));
		}
		~IndexedQueue() {
			delete [] mems;
		}
		
		void push(int x) {
			++csz;
			++mems[x];
			if (x > gt) gt = x;
		}
		
		int pop() {
			if (!csz) return -1;
			int result = gt;
			--mems[gt];
			if (--csz == 0) gt = -1;
			else while (!mems[gt]) --gt;
			return result;
		}
		
		int size() { return csz; }
		bool empty() { return csz==0; }
};


char sold[100001];
int main(){
	int T, n, m, k, x;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d%d", &k, &n, &m);
		IndexedQueue qb, qg;
		for (int i=0; i<n; ++i) {
			scanf("%d", &x);
			qg.push(x);
		}
		for (int i=0; i<m; ++i) {
			scanf("%d", &x);
			qb.push(x);
		}

		while (qg.size() && qb.size()) {
			int c = min(k, min(qb.size(), qg.size()));
			for (int i=0; i<c; ++i)
				sold[i] = qg.pop() - qb.pop();

			for (int i=0; i<c; ++i)
				if (sold[i])
					if (sold[i] > 0)
						 qg.push(+sold[i]);
					else qb.push(-sold[i]);
		}

		if (qg.size()) {
			puts("green wins");
			while (qg.size())
				printf("%d\n", qg.pop());
		}

		else if (qb.size()) {
			puts("blue wins");
			while (qb.size())
				printf("%d\n", qb.pop());
		}

		else puts("green and blue died");
		if (T) putchar('\n');
	}
}
