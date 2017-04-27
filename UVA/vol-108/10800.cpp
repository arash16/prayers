#include <stdio.h>
#include <cstring>
#include <iostream>
using namespace std;

int mxx[104];
char board[104][52];
int main() {
    int T;
    char s[100];
    scanf("%d", &T);
    for (int cse=1; cse<=T; cse++) {
        scanf("%s", s);
        memset(mxx, 0, sizeof(mxx));
        memset(board, ' ', sizeof(board));

        int x=0, y=50, mny=y, mxy=y-1;
        for (int i=0; s[i]; i++)
            if (s[i] == 'R') {
                mxx[y] = x + 1;
                if (y > mxy) mxy = y;
                board[y++][x++] = '/';
            }

            else if (s[i] == 'F') {
                board[--y][x++] = '\\';
                if (y < mny) mny = y;
                mxx[y] = x;
            }

            else {
                board[y][x++] = '_';
                mxx[y] = x;
                if (y > mxy) mxy = y;
            }


        printf("Case #%d:\n", cse);
        for (int i=mxy; i>=mny; i--) {
            printf("| ");
            for (int j=0; j<mxx[i]; j++)
                putchar(board[i][j]);
            putchar('\n');
        }
        putchar('+');
        for (int i=0; i<x+2; i++)
            putchar('-');
        puts("\n");
    }
}
