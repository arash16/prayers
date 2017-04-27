#include <math.h>
#include <stdio.h>

int gcd(int a, int b) {
	return !a ? b : gcd(b%a, a);
}

int phi(int n) {
	int sq = sqrt(n);
	int m = n;
	for (int i=2; i<=sq; i++)
		if (n%i == 0) {
			while (n%i==0) n /= i;
			m /= i;
			m *= i - 1;
			sq = sqrt(n);
		}
	if (n > 1) m = (m/n) * (n-1);
	return m;
}

void forward(int n, int &a, int &b, int &c, int &d) {
	int r = (n+b)/d,
	p = r*c-a,	q = r*d-b;
	a = c;		b = d;
	c = p;		d = q;
}

int szs[1001] = {0, 2};
int main() {
	for (int i=2; i<1001; i++)
		szs[i] = szs[i-1] + phi(i);

	int n, k;
	while (scanf("%d %d", &n, &k)==2) {
		int a=0,b=1, c=1,d=n, rev=0;
		if (k == szs[n]-1) c=d=1;
		else {
			if (k*2 > szs[n]) { 
				k = szs[n] - k - 1;
				rev = 1;
			}
			for (int i=1; i<k; i++)
				forward(n, a, b, c, d);
		
			if (rev) c = d-c;
		}
		printf("%d/%d\n", c, d);
	}
}
