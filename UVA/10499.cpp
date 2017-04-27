#include <stdio.h>
#include <iostream>
using namespace std;


int main() {
	long long int n;
	while (cin >> n && n > -1)
		printf("%lld%%\n", n>1 ? n * 25 : 0);
}