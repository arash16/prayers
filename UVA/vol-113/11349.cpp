#include <stdio.h>

inline int readchar() {
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


bool isdigit(char ch) { return ch>='0' && ch<='9'; }
inline long long readInt() {
	char ch;
	int sgn=1;
	long long r = 0;
	while (!isdigit(ch=readchar()) && ch!='-');
	if (ch == '-') sgn = -1;
	else r = ch-'0';
	while (isdigit(ch=readchar()))
		r = (r<<3) + (r<<1) + ch-'0';
	return sgn*r;
}

// -----------------------------------------------------------------

long long X[200][200];
bool isSymmetric(int n) {
	for (int i=0; i<n; ++i)
		for (int j=0; j<=i; ++j)
			if (X[i][j]<0 || X[i][j]!= X[n-i-1][n-j-1])
				return 0;
	return 1;
}

int main() {
	int T = readInt();
	for (int cse=1; cse<=T; ++cse) {
		while (readchar()!='=');

		int n = readInt();
		for (int i=0; i<n; ++i)
			for (int j=0; j<n; ++j)
				X[i][j] = readInt();

		printf("Test #%d: %s.\n", cse, isSymmetric(n) ? "Symmetric" : "Non-symmetric");
	}
}
