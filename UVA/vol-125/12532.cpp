#include <stdio.h>
#include <cstring>

inline char readchar() {
    const int N = 4194304;
    static char buf[N];
    static char *p = buf, *end = buf;
    if (p == end) {
        if ((end = buf + fread(buf, 1, N, stdin)) == buf) 
        	return EOF;
        p = buf;
    }
    return *p++;
}

inline char readCh() {
	char ch;
	while ((ch=readchar())==' ' || ch=='\n');
	return ch;
}

bool isdigit(char ch) { return ch>='0' && ch<='9'; }
inline int readInt() {
	char ch;
	int sgn=1, r=0;
	while (!isdigit(ch=readchar()) && ch!='-')
		if (ch == EOF)
			return 0;
	if (ch == '-') sgn = -1;
	else r = ch-'0';
	while (isdigit(ch=readchar()))
		r = (r<<3) + (r<<1) + ch-'0';
	return sgn*r;
}

// -------------------------------------------------------------------

#define LSB(i) ((i) & -(i))

void init(int BIT[], int size) {
	for (int i = 0; i < size; ++i) {
		int j = i + LSB(i+1);

		if (j < size)
			BIT[j] += BIT[i];
	}
}

bool update(int BIT[], int size, int i, int delta) {
	while (i < size) {
		BIT[i] += delta;
		i += LSB(i+1);
	} return 1;
}

int getRange(int BIT[], int i, int j) {
	int sum = 0;
	while (j > i) {
		sum += BIT[j-1];
		j -= LSB(j);
	}
	while (i > j) {
		sum -= BIT[i-1];
		i -= LSB(i);
	}
	return sum;
}

// -------------------------------------------------------------------

#define MAXN 100017
int n, k, BN[MAXN], BZ[MAXN], X[MAXN];

char result[MAXN];
int main() {
	while ((n=readInt()) && (k=readInt())) {
		for (int i=0; i<n; ++i) {
			X[i] = readInt();
			BZ[i] = !X[i];
			BN[i] = X[i]<0;
		}
		init(BZ, n);
		init(BN, n);

		int ri = 0;
		for (int i=0; i<k; ++i) {
			char cm = readCh();
			int x = readInt()-1,
				y = readInt();

			if (cm == 'C') {
				if (X[x] < 0)
					y>=0 && update(BN, n, x, -1);
				else y<0 && update(BN, n, x,  1);

				if (X[x])
					!y && update(BZ, n, x,  1);
				else y && update(BZ, n, x, -1);

				X[x] = y;
			}
			else result[ri++] = 
					getRange(BZ, x, y)   ? '0' :
					getRange(BN, x, y)&1 ? '-' : '+';
		}

		result[ri++] = '\n';
		fwrite_unlocked(result, 1, ri, stdout);
	}
}
