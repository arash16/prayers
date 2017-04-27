#include <bits/stdc++.h>
using namespace std;

inline int readchar(bool skip=true) {
    const int N = 4194304;
    static char buf[N];
    static char *p = buf, *end = buf;
    bool fin = 0;
    if (fin) return EOF;
    if (p == end) {
        if ((end = buf + fread(buf, 1, N, stdin)) == buf) {
        	fin = 1;
        	return EOF;
    	}
        p = buf;
    }
    int result = *p;
    if (skip) ++p;
    return result;
}

inline bool isdigit(char ch) { return ch>='0' && ch<='9'; }
inline int readUInt() {
	char ch;
	unsigned int r=0;
	while (!isdigit(ch=readchar()))
		if (ch == EOF) return EOF;
	r = ch-'0';
	while (isdigit(ch=readchar()))
		r = (r<<3) + (r<<1) + ch-'0';

	while (ch!=' ' && ch!='\n')
		ch = readchar();
	return r;
}

// ---------------------------------------------------------------

#define MAXP 1000012
int primes[80000], isnp[MAXP], pnt;
void sieve() {
	isnp[1] = 1;
	for (int i=2; i<MAXP; ++i)
		if (!isnp[i]) {
			primes[pnt++] = i;
			for (int j=i<<1; j<MAXP; j+=i)
				isnp[j] = 1;
		}
}

int divisors(int x){
	if (!isnp[x]) return 2;
    int result = 1;
    for (int i=0, p; (p=primes[i])*primes[i]<=x; ++i) 
    	if (x % p == 0) {
			int f = 1;
			while (x % p == 0) {
				x/=p;
				++f;
			}
			result *= f;
		}
	
	if (x > 1) result *= 2;
    return result;
}

int N[87000], nn;
int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);

	sieve();
	N[0] = 1;
	for (nn=1; N[nn-1]<1000000; ++nn)
		N[nn] = N[nn-1] + divisors(N[nn-1]);


	int T = readUInt();
	for (int cse=1; cse<=T; ++cse) {
		int l = readUInt(),
			r = readUInt(),
			ll = lower_bound(N, N+nn, l) - N - 1,
			rr = lower_bound(N, N+nn, r) - N;
		if (N[rr] != r) --rr;

		cout << "Case " << cse << ": " << rr-ll << "\n";
	}
}
