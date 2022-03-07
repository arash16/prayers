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


struct Str {
    char *str;
    Str *nxt;
    Str(char *str):nxt(0),str(str){}
};


bool termch[127];
char line[100017];
int main() {
    termch['[']=termch[']']=termch['\n']=true;

    int ind = 0;
    char last = ']', ch;
    Str *st=new Str(""), *ed=st;
    for (int i=0; (ch = line[i] = readchar())!=EOF; ++i)
        if (termch[ch]) {
            if (i > ind) {
                line[i] = 0;
                Str *s = new Str(line + ind);
                if (last == ']') {
                    ed->nxt = s;
                    ed = s;
                }
                else {
                    s->nxt = st;
                    st = s;
                }
            }

            if (ch == '\n') {
                for (Str *cur=st; cur; cur = cur->nxt)
                    printf("%s", cur->str);
                putchar('\n');
                last = ']';
                ind = 0; i = -1;
                st = ed = new Str("");
            }
            else {
                ind = i + 1;
                last = ch;
            }
        }
}
