/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10377
  Name: Maze Traversal
  Problem: https://onlinejudge.org/external/103/10377.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
using namespace std;

char M[100][100];
char readchar() {
    char ch;
    for (;(ch=getchar());)
        if (ch!=' ' && ch!='\n' && ch!='\t')
            return ch;
    return 'Q';
}

int RR[127], LL[127];
int main() {
    char alldirs[] = "NESW";
    for (int i=0; i<4; i++) {
        RR[alldirs[i]] = alldirs[(i+1)%4];
        LL[alldirs[i]] = alldirs[(i+3)%4];
    }

    char cm;
    int T, n, m, cx, cy;
    cin>>T;
    while (T--) {
        cin >> n >> m;
        cin.getline(M[0], 100);
        for (int i=0; i<n; i++)
            cin.getline(M[i], 100);

        char dir='N';
        cin>>cy>>cx; cy--; cx--;
        while ((cm=readchar()) != 'Q')
            switch (cm) {
                case 'R': dir = RR[dir]; break;
                case 'L': dir = LL[dir]; break;
                case 'F':
                    int ncx=cx, ncy=cy;
                    switch (dir) {
                        case 'N': ncy--; break;
                        case 'E': ncx++; break;
                        case 'S': ncy++; break;
                        case 'W': ncx--; break;
                    }

                    if (ncx>=0 && ncx<m && ncy>=0 && ncy<n && M[ncy][ncx]==' ') {
                        cx = ncx;
                        cy = ncy;
                    }
            }

        printf("%d %d %c\n", cy+1, cx+1, dir);
        if (T) putchar('\n');
    }
}
