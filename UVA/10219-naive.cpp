#include <math.h>
#include <stdio.h>
#include <iostream>
using namespace std;

double logfact(int n, int k) {
	if (n-k < k) k = n-k;
	
	double res = log10(n);
	for (int i=1; i<k; i++)
		res += log10(n-i) - log10(i+1);
	
	return res;
}

int main() {
	int n, k;
	while (cin>>n>>k)
		cout << floor(logfact(n, k))+1 << endl;
}
