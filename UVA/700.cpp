#include <stdio.h>

int R[30], A[30], S[30], n;
bool check(int x) {
	for (int i=0; i<n; ++i)
		if ((x-A[i]) % S[i] != R[i])
			return 0;
	return 1;
}

int main() {
	for (int cse=1; scanf("%d", &n) && n; ++cse) {
		int y, a, b, result = 0;
		for (int i=0; i<n; ++i) {
			scanf("%d%d%d", &y, A+i, &b);
			if (y < A[i] || y >= b) 
				result = 100001;
			else {
				S[i] = b - A[i];
				R[i] = y - A[i];
				if (y > result)
					result = y;
			}
		}

		for (; result<10000; ++result)
			if (check(result))
				break;
		
		printf("Case #%d:\n", cse);
		if (result < 10000)
			 printf("The actual year is %d.\n\n", result);
		else puts("Unknown bugs detected.\n");
	}
}
