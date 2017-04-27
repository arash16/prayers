#include <stdio.h>
#include <iostream>
using namespace std;

int main() {
	int C;
	cin >> C;
	for (int c = 1; c <= C; c++) {
		int n, x, y, h = 0, l = 0;
		cin >> n >> x;
		while (--n) {
			cin >> y;
			if (y > x) h++;
			if (y < x) l++;
			x = y;
		}

		printf("Case %d: %d %d\n", c, h, l);
	}
}