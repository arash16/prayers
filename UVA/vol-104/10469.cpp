#include <stdio.h>
#include <iostream>
using namespace std;

int main() {
	long int x, y;
	while (cin >> x >> y)
		cout << (x ^ y) << endl;
}