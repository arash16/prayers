#include <stdio.h>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define sqr(x) ((x)*(x))

#define MAX 100000000
char memo[MAX];
bool isHappy(int x) {
	if (x == 1) return true;
	if (x < MAX) {
		if (memo[x]) 
			return memo[x] == 1;
		memo[x] = -1;
	}

	int n = 0;
	for (int k = x; k; k /= 10) {
		int m = k % 10;
		n += m*m;
	}

	bool r = isHappy(n);
	if (r && x < MAX) memo[x] = 1;
	return r;
}


int main() {
	int n;
	cin >> n;
	for (int cse = 1; cse <= n; cse++) {
		int x;
		cin >> x;
		if (isHappy(x))
			printf("Case #%d: %d is a Happy number.\n", cse, x);
		else
			printf("Case #%d: %d is an Unhappy number.\n", cse, x);
	}
}