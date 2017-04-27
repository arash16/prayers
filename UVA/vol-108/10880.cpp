#include <math.h>
#include <stdio.h>

inline int readchar() {
    const int N = 1048576;
    static char buf[N];
    static char *p = buf, *end = buf;
    if (p == end) {
        if ((end = buf + fread(buf, 1, N, stdin)) == buf) 
        	return EOF;
        p = buf;
    }
    return *p++;
}

bool isdigit(char ch) { return ch>='0' && ch<='9'; }
inline int readInt() {
	char ch;
	int sgn=1, r=0;
	while (!isdigit(ch=readchar()) && ch!='-');
	if (ch == '-') sgn = -1;
	else r = ch-'0';
	while (isdigit(ch=readchar()))
		r = (r<<3) + (r<<1) + ch-'0';
	return sgn*r;
}

char buf[50];
void print(long long x) {
	int i=48;
	if (!x) buf[i--] = '0';
	for (; x; x/=10)
		buf[i--] = x%10 + '0';
	buf[i--] = ' ';
	fwrite_unlocked(buf+i+1, 1, 48-i, stdout);
}

// --------------------------------------------------------------

int stk[100000];
int main() {
	int T = readInt();
	for (int cse=1; cse<=T; ++cse) {
		printf("Case #%d:", cse);
		int c = readInt(),
			r = readInt();

		if (c == r) print(0);
		else if (c) {
			int n = c - r,
				sq = sqrt(n),
				si = 0;

			if (!r) print(1);
			if (n>1) stk[si++] = n;
			for (int i=2; i<=sq; ++i)
				if (n%i == 0) {
					if (c%i == r)
						print(i);
					stk[si++] = n/i;
				}

			if (stk[si-1] && n/stk[si-1] == stk[si-1]) si--;
			for (int i=si-1; i>=0; --i)
				if (c % stk[i] == r)
					print(stk[i]);
		}
		putchar('\n');
	}
}
