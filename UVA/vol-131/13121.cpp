/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 13121
  Name: Eclipsing Gianik Star
  Problem: https://onlinejudge.org/external/131/13121.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <math.h>
#include <stdio.h>
#include <iostream>
using namespace std;

#define INF 1073741824
int abs(int x) { return x<0 ? -x : x; }

struct Triple {
    int d, x, y;
    Triple(int q, int w, int e):d(q),x(w),y(e){}
};

Triple egcd(int a, int b) {
    if (!b) return Triple(a, 1, 0);
    Triple q = egcd(b, a%b);
    return Triple(q.d, q.y, q.x - a/b * q.y);
}


int a[400], b[400];
int nexte(int i, int j) {
    if (b[i] == b[j]) return a[i]==a[j] ? 0 : INF;
    if (b[i] < b[j]) swap(i, j);

    int bij = b[i]-b[j],
        aji = a[j]-a[i];
    if (aji < 0) aji += 360*ceil(-aji / 360.0);


    Triple t = egcd(bij, 360);
    if (aji % t.d) return INF;
    int x = (aji/t.d * t.x) % 360;
    if (x < 0) x += 360;
    int mn = INF;
    for (int i=0; i<t.d; i++) {
        int tm = (x + i*360/t.d) % 360;
        if (tm>=0 && tm<mn) mn = tm;
        if (!mn) return mn;
    }
    return mn;
}

int main(){
    int n;
    while (scanf("%d", &n)==1) {
        int mn = INF;
        for (int i=0; i<n; i++) {
            scanf("%*d%d%d", a+i, b+i);
            a[i] = (a[i]%360+360)%360;
            if (mn) for (int j=0; j<i; j++)
                mn = min(mn, nexte(j, i));
        }

        if (mn == INF) puts("GIANIK IS NEVER ECLIPSED");
        else printf("%d\n", mn);
    }
}
