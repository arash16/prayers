#include <math.h>
#include <stdio.h>
#include <iostream>
using namespace std;

#define EPS 1e-8
int main(){
	double lg18 = log2(18),
			lg9 = log2(9)/lg18;
	long long int n;
	while (cin>>n) {
		double t = log2(n)/lg18;
		t = t - (int)t;
		cout << (t>EPS && t<=lg9+EPS ? "Stan wins." : "Ollie wins.") << endl;
	}
}
