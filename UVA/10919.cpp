#include <stdio.h>

inline int readchar() {
    const int N = 1048576;
    static char buf[N];
    static char *p = buf, *end = buf;
    if(p == end) {
        if((end = buf + fread(buf, 1, N, stdin)) == buf) return EOF;
        p = buf;
    }
    return *p++;
}

bool isdigit(char ch) { return ch>='0' && ch<='9'; }
inline unsigned int readUInt() {
	char ch;
	unsigned int r=0;
	while (!isdigit(ch=readchar()));
	r = ch-'0';
	while (isdigit(ch=readchar()))
		r = (r<<3) + (r<<1) + ch-'0';
	return r;
}



int main() {
	int taken[10000];
	for (int cse=1, n; (n = readUInt()); ++cse) {
		int m = readUInt();
		for (int i=0; i<n; ++i)
			taken[readUInt()] = cse;

		bool valid = true;
		for (int i=0; i<m; ++i) {
			int d = readUInt(),
				mn = readUInt();
			for (int i=0; i<d; ++i)
				if (taken[readUInt()] == cse) 
					--mn;
			if (mn > 0) valid = false;
		}

		puts(valid ? "yes" : "no");
	}
}

