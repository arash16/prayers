/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 11988
  Name: Broken Keyboard (a.k.a. Beiju Text)
  Problem: https://onlinejudge.org/external/119/11988.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

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


bool term[127];
char line[100017], out[100017];
int nxt[100017];
int main() {
    term['[']=term[']']=term['\n']=1;

    int st=0, ed=-1, ind=0;
    char last = ']', ch;
    for (int i=0; (ch = line[i] = readchar())!=EOF; ++i) {
        nxt[i] = i + 1;
        if (term[ch]) {
            if (i > ind) {
                if (last == ']') {
                    if (ed >= 0)
                        nxt[ed] = ind;
                    ed = i-1;
                }
                else {
                    nxt[i-1] = st;
                    st = ind;
                    if (ed == -1)
                        ed = i-1;
                }
            }

            if (ch == '\n') {
                int k = 0;
                if (i) {
                    nxt[ed]=-1;
                    for (int j=st; j>=0; j=nxt[j])
                        out[k++] = line[j];
                }
                out[k] = '\n';
                fwrite_unlocked(out, 1, k+1, stdout);

                last = ']';
                st = ind = 0;
                ed = i = -1;
            }
            else {
                ind = i--;
                last = ch;
            }
        }
    }
}
