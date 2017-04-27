#include <stdio.h>
#include <iostream>
using namespace std;

int main() {
	int m, n;
	while (scanf("%d%d", &n, &m) == 2)
		cout << n*m - 1 << endl;
}