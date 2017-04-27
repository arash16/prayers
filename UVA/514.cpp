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

// --------------------------------------------------------------------------

class FastStack {
	int data[1024], sz;
	public:
		FastStack():sz(0){}
		void clear() { sz=0; }
		bool empty() { return !sz; }
		void push(int x) { data[sz++] = x; }
		int pop() { return data[--sz]; }
		int top() { return data[sz-1]; }
		int size() { return sz; }
};



int blocks[1001];
FastStack src, station;
bool test(int n) {
	src.clear();
	station.clear();
	for (int i=n; i>0; i--)
		src.push(i);

	for (int i=0; i<n; i++) {
		int x = blocks[i];
		if (station.size() && station.top()==x)
			station.pop();
		else do {
			if (!src.size()) return false;
			
			int stop = src.top();
			src.pop();
			if (stop == x) break;
			station.push(stop);
		} while(true);
	}
	
	return true;
}


int main(){
	int n;
	while ((n=readUInt())) {
		while ((blocks[0]=readUInt())) {
			for (int i=1; i<n; i++)
				blocks[i] = readUInt();
			puts(test(n) ? "Yes" : "No");
		}
		putchar('\n');
	}
}
