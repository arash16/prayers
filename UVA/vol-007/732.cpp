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

bool readStr(char *str) {
    char ch;
    while ((ch=readchar())==' ' || ch=='\n');
    if (ch == EOF) return 0;

    *str++ = ch;
    while ((ch=readchar())!=' ' && ch!='\n' && ch!=EOF)
        *str++ = ch;
    *str = 0;
    return 1;
}

// ---------------------------------------------------------------------------

char w1[1000], w2[1000],
    stk[1000], res[1000];
void recurse(int si, int i, int j) {
    if (!w2[j]) {
        if (!si && !w1[i]) {
            putchar(res[0]);
            for (int k=1; k<i+j; ++k) {
                putchar(' ');
                putchar(res[k]);
            }
            putchar('\n');
        }
        return;
    }

    if (w1[i]) {
        res[i+j] = 'i';

        char t = stk[si];
        stk[si] = w1[i];
        recurse(si+1, i+1, j);
        stk[si] = t;
    }

    if (si && w2[j] == stk[si-1]) {
        res[i+j] = 'o';
        recurse(si-1, i, j+1);
    }
}

int main() {
    while (readStr(w1) && readStr(w2)) {
        puts("[");
        recurse(0, 0, 0);
        puts("]");
    }
}
