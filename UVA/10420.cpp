#include <stdio.h>
#include <iostream>
using namespace std;

int main() {
	int a[1001], n;
	while (cin >> n) {
		int result = 0;

		for (int i = 0; i < n; i++)
			cin >> a[i];

		for (int i = 0; i<n; i++)
			for (int j = 0; j<n - 1; j++)
				if (a[j] > a[j + 1]) {
					result++;
					a[j] = a[j] ^ a[j + 1];
					a[j + 1] = a[j] ^ a[j + 1];
					a[j] = a[j] ^ a[j + 1];
				}

		printf("Minimum exchange operations : %d\n", result);
	}
}