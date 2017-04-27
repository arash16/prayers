#include <stdio.h>
#include <math.h>
#include <iostream>
using namespace std;

int main() {
	long long int n;
	while ((cin>>n) && n) {
		long long int sq = sqrt(n);
		cout << (sq*sq == n ? "yes" : "no") << endl;
	}
}

