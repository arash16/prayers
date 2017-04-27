#include <stdio.h>
#include <unordered_map>
using namespace std;

int main(){
	srand(rand());
	int rnd = rand();

	int T, n, m, x;
	scanf("%d", &T);
	while (T--) {
		unordered_map<int, int> dif(20000);
		scanf("%d%d", &n, &m);
		int cnt = n + m;

		for (int i=0; i<n; ++i) {
			scanf("%d", &x);
			++dif[x^rnd];
		}

		for (int i=0; i<m; ++i) {
			scanf("%d", &x); x^=rnd;
			auto it = dif.find(x);
			if (it!=dif.end() && it->second) {
				--it->second;
				cnt -= 2;
			}
		}

		printf("%d\n", cnt);
	}
}
