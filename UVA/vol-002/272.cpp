#include <stdio.h>
#include <iostream>
using namespace std;

int main() {
	char ch;
	bool f = false;
	while (scanf("%c", &ch) == 1) {
		if (ch == '"') {
			cout << (f ? "''" : "``");
			f = !f;
		}
		else cout << ch;
	}
}
