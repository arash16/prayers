#include <stdio.h>
#include <iostream>
using namespace std;


int main() {
	int n;
	while ((cin >> n) && n) {
		while (n > 9) {
			int s = 0;
			while (n) {
				s += n % 10;
				n /= 10;
			}
			n = s;
		}
		cout << n << endl;
	}
}
