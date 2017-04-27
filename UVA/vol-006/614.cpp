#include <stdio.h>
#include <iostream>
using namespace std;

int h, w, gy, gx, M[20][20], R[20][20];
bool dfs(int x, int y, int d) {
    if (R[y][x] >= 0)
        return false;

    R[y][x] = d;
    if (x == gx && y == gy)
        return true;

    // Move Left
    if (x>0 && !(M[y][x-1]&1))
        if (dfs(x-1, y, d+1))
            return true;

    // Move Up
    if (y>0 && !(M[y-1][x]&2))
        if (dfs(x, y-1, d+1))
            return true;

    // Move Right
    if (!(M[y][x]&1))
        if (dfs(x+1, y, d+1))
            return true;

    // Move Down
    if (!(M[y][x]&2))
        if (dfs(x, y+1, d+1))
            return true;

    return R[y][x] = 0;
}

int main(){
    int cse=1, sx, sy;
    while (cin>>h>>w>>sy>>sx>>gy>>gx && (h||w)) {
        for (int i=0; i<h; i++) {
            for (int j=0; j<w; j++) {
                cin>>M[i][j];

                R[i][j] = -1;
                if (i==h-1)
                    M[i][j] |= 2;
            }
            M[i][w-1] |= 1;
        }

        gx--; gy--;
        dfs(sx-1, sy-1, 1);

        printf("Maze %d\n\n", cse++);
        for (int i=0; i<w; i++)
            printf("+---");
        puts("+");

        for (int i=0; i<h; i++) {
            putchar('|');
            for (int j=0; j<w; j++) {
                if (R[i][j] < 0) printf("   ");
                else if (!R[i][j]) printf("???");
                else printf("%3d", R[i][j]);

                putchar(M[i][j]&1 ? '|' : ' ');
            }
            putchar('\n');

            for (int j=0; j<w; j++)
                printf(M[i][j]&2 ? "+---" : "+   ");
            puts("+");
        }

        puts("\n");
    }
}
