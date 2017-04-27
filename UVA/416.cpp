#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

#define sub(a, b) ((a) & ~(b))

int numbers[] = { 126, 48, 109, 121, 51, 91, 95, 112, 127, 123 };

bool areMatch(int inps[], int n, int s) {
	int burned = 0;
	for (int i = n - 1; i >= 0; i--) {
		int g = sub(numbers[s + i], burned);

		if ((inps[i] & g) != inps[i])
			return false;
	
		burned |= sub(g, inps[i]);
	}

	return true;
}


bool isMatch(int inps[], int n) {
	for (int i = 0; i < 10 - n + 1; i++)
		if (areMatch(inps, n, i))
			return true;

	return false;
}


int main() {
	int n;
	char num[8];

	while (cin >> n && n) {
		int inps[10];

		for (int k = 0; k < n; k++) {
			while (getchar() != '\n');

			int x = 0;
			for (int i = 0; i < 7; i++)
				x = (x << 1) | (getchar() == 'Y');

			inps[n - k - 1] = x;
		}


		if (!isMatch(inps, n)) 
			cout << "MIS";
		cout << "MATCH\n";
	}
}
