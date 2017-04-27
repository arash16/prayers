#include <stdio.h>
#include <iostream>
using namespace std;

int max(int a, int b) { return a > b ? a : b; }
int min(int a, int b) { return a < b ? a : b; }

int main() {
	int C;
	cin >> C;
	for (int c = 1; c <= C; c++) {
		int x, y, z, r;
		cin >> x >> y >> z;

		printf("Case %d: %d\n", c, (x >= min(y, z) && x <= max(y, z)) ? x : (y >= min(x, z) && y <= max(x, z)) ? y : z);
	}
}