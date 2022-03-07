/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10503
  Name: The dominoes solitaire
  Problem: https://onlinejudge.org/external/105/10503.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
using namespace std;

int x[20], y[20], n, m, e1,
    seen[32768][100][20], cse=0;

bool canPlace(int used, int last, int ind) {
    if (ind == n) return last == e1;
    if (seen[used][last][ind] == cse)
        return false;
    seen[used][last][ind] = cse;

    int msk = 1;
    for (int i=0; i<m; i++, msk<<=1)
        if (!(used & msk)) {
            if (x[i]==last) {
                if (canPlace(used|msk, y[i], ind+1))
                    return true;
            }

            else if (y[i]==last) {
                if (canPlace(used|msk, x[i], ind+1))
                    return true;
            }
        }
    return false;
}

int main(){
    int s1, s2, e2;
    while (scanf("%d%d", &n, &m)==2 && n) {
        scanf("%d%d%d%d", &s1,&s2, &e1,&e2);
        for (int i=0; i<m; i++)
            scanf("%d%d", x+i, y+i);

        cse++;
        puts(canPlace(0, s2, 0) ? "YES" : "NO");
    }
}
