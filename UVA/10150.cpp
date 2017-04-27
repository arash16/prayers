#include <bits/stdc++.h>
using namespace std;

inline int readchar() {
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
    return *p++;
}

inline int readLine(char *str) {
	int len=0;
	char ch;
	while ((ch=readchar())!='\n' && ch!=EOF)
		str[len++] = ch;

	str[len] = 0;
	if (ch == EOF && !len) return EOF;
	return len;
}

inline bool readStr(char *str) {
	char ch;
	while ((ch=readchar())==' ' || ch=='\n');
	if (ch == EOF) return 0;

	*str++ = ch;
	while ((ch=readchar())!=' ' && ch!='\n' && ch!=EOF)
		*str++ = ch;
	*str = 0;
	return 1;
}

// --------------------------------------------------------------------------

int seen[25144], pre[25144];
vector<int> adj[25144];
char words[25144][17];

int S[402304][26], SW[402304], scnt;
int findW(char s[], int cur=0) {
	for (int i=0; s[i]; ++i) {
		char chi = s[i]-'a';

		if (!S[cur][chi]) 
			return 0;
		cur = S[cur][chi];
	}
	return SW[cur];
}

void insertW(int wi) {
	char *s = words[wi];
	int cur = 0;
	for (int i=0; s[i]; ++i) {
		char chi = s[i]-'a';

		for (int j=0; j<26; ++j)
			if (chi != j && S[cur][j]) {
				int wj = findW(s+i+1, S[cur][j]);
				if (wj > 0) {
					adj[wi].push_back(wj);
					adj[wj].push_back(wi);
				}
			}

		if (!S[cur][chi])
			S[cur][chi] = ++scnt;
		cur = S[cur][chi];
	}
	SW[cur] = wi;
}


void printPath(int src, int dst) {
	if (src == dst) {
		cout << words[src] << endl;
		return;
	}

	printPath(src, pre[dst]);
	cout << words[dst] << endl;
}


int main() {
	for (int i=1; readLine(words[i]); ++i)
		insertW(i);

	char s1[20], s2[20];
	for (int cse=1; readStr(s1) && readStr(s2); ++cse) {
		if (cse > 1) cout << endl;

		int src = findW(s1),
			dst = findW(s2);

		if (src && dst) {
			seen[src] = cse;
			queue<int> q;
			q.push(src);
			while (!q.empty()) {
				int u = q.front(); q.pop();
				for (int v: adj[u])
					if (seen[v]!=cse) {
						seen[v] =cse;
						pre[v] = u;

						if (v == dst) {
							printPath(src, dst);
							goto fin;
						}
						q.push(v);
					}
			}
		}
		cout << "No solution.\n";
		fin:;
	}
}
