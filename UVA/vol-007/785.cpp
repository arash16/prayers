#include <cstring>
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

int readLine(char *str) {
    int l=0;
    char ch;
    while ((ch=readchar())!='\n' && ch!=EOF) {
        *str++ = ch;
        ++l;
    }
    *str = 0;
    return ch == EOF && !l ? EOF : l;
}

// --------------------------------------------------------------

char M[32][81], w[31], sep, h;
void dfs(int y, int x, char c) {
    if (x >= w[y]) return;
    M[y][x] = c;

    if (x>0 && M[y][x-1] == ' ')
        dfs(y, x-1, c);

    if (M[y][x+1] == ' ')
        dfs(y, x+1, c);

    if (y>0 && M[y-1][x] == ' ')
        dfs(y-1, x, c);

    if (y<h-1 && M[y+1][x] == ' ')
        dfs(y+1, x, c);
}

int main() {
    while ((w[h]=readLine(M[h])) != EOF)
        if (M[h][0]=='_') {
            for (int i=0; i<h; ++i) {
                for (int j=0; M[i][j]; ++j)
                    if (M[i][j] != sep && M[i][j] != ' ') {
                        char col = M[i][j];
                        dfs(i, j, col);
                        while (M[i][j] == col) ++j;
                    }
            }

            for (int i=0, l; i<=h; ++i) {
                for (l=0; M[i][l]; ++l);
                M[i][l] = '\n';
                fwrite_unlocked(M[i], 1, l+1, stdout);
            }

            sep=h=0;
        }
        else {
            ++h;
            for (int i=0; !sep && M[h-1][i]; ++i)
                if (M[h-1][i] != ' ')
                    sep = M[h-1][i];
        }
}
