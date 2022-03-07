/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 190
  Name: Circle Through Three Points
  Problem: https://onlinejudge.org/external/1/190.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <math.h>
#include <stdio.h>
#include <iostream>
using namespace std;

#define EPS 1e-9

bool lineIntersect(double x[], double y[], double r[]) {
    double n[2]; n[0] = y[3] - y[2]; n[1] = x[2] - x[3];
    double denom = n[0] * (x[1] - x[0]) + n[1] * (y[1] - y[0]);
    if (fabs(denom) < EPS) return false;

    double num = n[0] * (x[0] - x[2]) + n[1] * (y[0] - y[2]);
    double t = -num / denom;
    r[0] = x[0] + t * (x[1] - x[0]);
    r[1] = y[0] + t * (y[1] - y[0]);
    return true;
}

double circle3pts(double x[], double y[], double r[]) {
    double lix[4], liy[4];
    lix[0] = 0.5 * (x[0] + x[1]); liy[0] = 0.5 * (y[0] + y[1]);
    lix[1] = lix[0] + y[1] - y[0];  liy[1] = liy[0] + x[0] - x[1];
    lix[2] = 0.5 * (x[1] + x[2]); liy[2] = 0.5 * (y[1] + y[2]);
    lix[3] = lix[2] + y[2] - y[1];  liy[3] = liy[2] + x[1] - x[2];
    if (!lineIntersect(lix, liy, r)) return -1.0;
    return sqrt(
        (r[0] - x[0]) * (r[0] - x[0]) +
        (r[1] - y[0]) * (r[1] - y[0]) );
}

char sgn(double x) {
    return x<0 ? '-' : '+';
}

void printXY2(char xy, double offset) {
    double aof = offset < 0 ? -offset : offset;
    if (aof < EPS)
        cout << xy << "^2";
    else
        printf("(%c %c %.3f)^2", xy, sgn(-offset), aof);
}

void printXY(double a, char xy) {
    double aof = a < 0 ? -a : a;
    if (aof > EPS)
        printf(" %c %.3f%c", sgn(a), aof, xy);
}

int main(){
    double x[3], y[3], c[3], r, cx, dy, e;
    while (scanf("%lf %lf %lf %lf %lf %lf", x,y, x+1,y+1, x+2,y+2)==6) {
        r = circle3pts(x, y, c);

        printXY2('x', c[0]);
        cout << " + ";
        printXY2('y', c[1]);
        printf(" = %.3f^2\n", r);

        cx = -2*c[0];
        dy = -2*c[1];
        e = r*r - c[0]*c[0] - c[1]*c[1];
        cout << "x^2 + y^2";
        printXY(cx, 'x');
        printXY(dy, 'y');
        printf(" %c %.3f = 0\n\n", sgn(-e), e<0?-e:e);
    }
}
