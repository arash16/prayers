#include <stdio.h>

inline int readchar() {
    const int N = 4194304;
    static char buf[N];
    static char *p = buf, *end = buf;
    if(p == end) {
        if((end = buf + fread(buf, 1, N, stdin)) == buf) return EOF;
        p = buf;
    }
    return *p++;
}
inline bool isdigit(char ch) { return ch>>4 == 3; }
inline unsigned int readUInt() {
	char ch;
	unsigned int r=0;
	while (!isdigit(ch=readchar()));
	r = ch-'0';
	while (isdigit(ch=readchar()))
		r = (r<<3) + (r<<1) + ch-'0';
	return r;
}

char buf[50];
void print(int x) {
	if (x) {
		int i=30;
		buf[i--] = '\n';
		for (; x; x/=10)
			buf[i--] = x%10 + '0';
		fwrite_unlocked(buf+i+1, 1, 30-i, stdout);
	}
	else fwrite_unlocked(buf+40, 1, 2, stdout);
}

int main() {
	buf[40]='0';
	buf[41]='\n';
	int T = readUInt();
	while (T--) {
		readUInt();
		int k = readUInt();
		print(k^(k>>1));
	}
}
