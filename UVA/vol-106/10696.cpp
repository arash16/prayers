#include <stdio.h>
#include <iostream>
using namespace std;

int p[101];
int f(int x) {
	if (x > 100) return x - 10;
	if (p[x]) return p[x];
	return p[x] = f(f(x + 11));
}

int main() {
	int n;
	while ((cin >> n) && n)
		printf("f91(%d) = %d\n", n, f(n));
}
