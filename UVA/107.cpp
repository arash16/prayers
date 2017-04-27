#include <stdio.h>
#include <math.h>
#include <iostream>
using namespace std;

#define EPS 1e-8

bool eq(double a, double b) {
	return (a<b?b-a:a-b) < EPS;
}

int findk(long long int h, long long int n, long long int &N) {
	double ll = log(n);
	for (N=2; N<=n; N++)
		if (n%N==0) {
			double k = ll/log(N);
			if (eq(1, h*pow(1.0/(N+1), k)))
				return round(k);
		}

	return -1;
}

double sigma(double r, long long int k) {
	return (1.0-pow(r, k+1.0)) / (1.0-r);
}

int main(){
	long long int h, n, N, k, a, b;
	while (cin >> h >> n && (h||n)) {
		if (n == 1) {
			a = log2(h);
			b = (1LL << (a+1)) - 1;
		}
		else {
			k = findk(h, n, N);
			a = round(sigma(N, k-1));
			b = round(h * sigma((double)N/(N+1.0), k));
		}
		printf("%lld %lld\n", a, b);
	}
}
