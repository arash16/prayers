#include <stdio.h>
#include <iostream>
using namespace std;

int cum[100001] = { 1, 2 };
int main() {
	for (int i = 1, j = 0, c = 0; j < 100001; i++)
		for (c++; j < i*i && j < 100001; j++)
			cum[j] = c;

	int a, b;
	while ((cin >> a >> b) && a)
		cout << cum[b] - cum[a - 1] << endl;
}