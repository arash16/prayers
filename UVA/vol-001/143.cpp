#include <math.h>
#include <stdio.h>
#include <iostream>
using namespace std;

#define EPS 1e-9
#define INF 1073741824

bool lineSegIntersect(double p0[], double p1[], double p2[], double p3[]) {
    double ucrossv1 = ( p1[0] - p0[0] ) * ( p2[1] - p0[1] ) - ( p1[1] - p0[1] ) * ( p2[0] - p0[0] );
    double ucrossv2 = ( p1[0] - p0[0] ) * ( p3[1] - p0[1] ) - ( p1[1] - p0[1] ) * ( p3[0] - p0[0] );
    if (ucrossv1 * ucrossv2 > 0) return false;

    double vcrossu1 = ( p3[0] - p2[0] ) * ( p0[1] - p2[1] ) - ( p3[1] - p2[1] ) * ( p0[0] - p2[0] );
    double vcrossu2 = ( p3[0] - p2[0] ) * ( p1[1] - p2[1] ) - ( p3[1] - p2[1] ) * ( p1[0] - p2[0] );

    return vcrossu1 * vcrossu2 <= 0;
}

bool lineIntersect(double p0[], double p1[], double p2[], double p3[], double r[] ) {
    double n[2]; n[0] = p3[1] - p2[1]; n[1] = p2[0] - p3[0];
    double denom = n[0] * ( p1[0] - p0[0] ) + n[1] * ( p1[1] - p0[1] );
    if (fabs( denom ) < EPS) return false;

    double num = n[0] * ( p0[0] - p2[0] ) + n[1] * ( p0[1] - p2[1] );
    double t = -num / denom;
    r[0] = p0[0] + t * ( p1[0] - p0[0] );
    r[1] = p0[1] + t * ( p1[1] - p0[1] );
    return true;
}

double p[3][2];
int findLR(int y) {
    double mnx = INF, mxx = -INF;
    double ly0[] = {-1000, y},
           ly1[] = { 1000, y},
           r[2];

    for (int i=0; i<3; i++)
        if (lineSegIntersect(p[i], p[(i+1)%3], ly0, ly1) && lineIntersect(p[i], p[(i+1)%3], ly0, ly1, r)) {
            if (r[0] < mnx)
                mnx = r[0];

            if (r[0] > mxx)
                mxx = r[0];
        }

    return min(99.0, floor(mxx+EPS)) - max(1.0, ceil(mnx-EPS)) + 1;
}

int main(){
    while (cin>>p[0][0]>>p[0][1]>>p[1][0]>>p[1][1]>>p[2][0]>>p[2][1]) {
        bool nonz=0;
        for (int i=0; !nonz && i<3; i++)
            if (p[i][0] || p[i][1])
                nonz=1;
        if (!nonz) break;

        int mny = max(1.0, ceil(min( min(p[0][1], p[1][1]), p[2][1]))),
            mxy = min(99.0, floor(max( max(p[0][1], p[1][1]), p[2][1]))),
            result = 0;

        for (int y=mny; y<=mxy; y++)
            result += findLR(y);

        printf("%4d\n", result);
    }
}
