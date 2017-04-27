#include <stdio.h>
#include <algorithm>
using namespace std;

int coins[] = {5, 10, 20, 50, 100, 200},
	changes[101], order[101];
bool comp(int i, int j) { return changes[i]<changes[j]; }


int naive(int n) {
	int result = 0;
	for (int i=5; n && i>=0; i--) {
		result += n / coins[i];
		n = n % coins[i];
	}

	return result;
}

int naive(int n, int x[]) {
	int res = 0;
	for (int i=5; n && i>=0; i--) if (x[i]) {
		int cc = min(x[i], n/coins[i]);
		n -= cc * coins[i];
		res += cc;
	}
	return n ? 100 : res;
}


int main () {
	for (int i=0; i<=100; i++) {
		changes[i] = naive(5*i);
		order[i] = i;
	}
	stable_sort(order, order+101, comp);

	int x[6]; float mm;
	while (scanf("%d%d%d%d%d%d %f",x,x+1,x+2,x+3,x+4,x+5, &mm)==7) {
		int m = mm * 100 + 0.5, t = 0;
		for (int i=0; i<6; i++)
			t += x[i]*coins[i];

		int best = 100;
		for (int i=0; i<=100; i++) {
			int exi = order[i];
			if (changes[exi] >= best) break;
			if (m + exi*5 <= t)
				best = min(best, changes[exi] + naive(m + exi*5, x));
		}

		printf("%3d\n", best);
	}
}

