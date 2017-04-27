#include <stdio.h>
#include <iostream>
using namespace std;

#define MAX 10000000
long long int memo[MAX];
long long int alen(long long int n, int d) {
	if (n == 1) return 1;
	if (!d || n<0) return -1e7;
	if (n < MAX && memo[n]) return memo[n];

	long long int x = n;
	int b = 0;
	for (; !(x&1); x>>=1)
		b++;


	long long int r = 1;
	if (x < MAX && memo[x]) 
		r = memo[x];

	else if (x>1 && 3*x+1>0) {
		r = alen(3*x + 1, d-1) + 1;
		if (x < MAX && r>0) memo[x] = r;
	}

	if (n < MAX && r>0) memo[n] = b + r;
	return b + r;
}

int main(){
	bool b;
	long long int l, r;
	while (cin>>l>>r && (l||r)) {
		long long int best = 0;
		if ((b = r < l)) {
			r ^= l;
			l ^= r;
			r ^= l;
		}
		
		for (long long int i=r; i>=l; i--) {
			long long int al = alen(i, 800);
			if (al >= best) best = al;
		}
		
		printf("%lld %lld %lld\n", b?r:l, b?l:r, best);
	}
}

