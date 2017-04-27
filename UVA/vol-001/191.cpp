#include <stdio.h>
#include <iostream>
using namespace std;

#define EPS 1e-9
#define EPS2 1e-10

double r1[2], r2[2];
double l1[2], l2[2];

bool pointInR(double x, double y) {
    return x>=r1[0] && x<=r2[0] && y>=r1[1] && y<=r2[1];
}

bool intersec(double p1[2], double p2[2], double p3[2], double p4[2]) {
    double ucrossv1 = ( p2[0] - p1[0] ) * ( p3[1] - p1[1] ) - ( p2[1] - p1[1] ) * ( p3[0] - p1[0] );
    double ucrossv2 = ( p2[0] - p1[0] ) * ( p4[1] - p1[1] ) - ( p2[1] - p1[1] ) * ( p4[0] - p1[0] );
    if (ucrossv1 * ucrossv2 > 0) return false;

    double vcrossu1 = ( p4[0] - p3[0] ) * ( p1[1] - p3[1] ) - ( p4[1] - p3[1] ) * ( p1[0] - p3[0] );
    double vcrossu2 = ( p4[0] - p3[0] ) * ( p2[1] - p3[1] ) - ( p4[1] - p3[1] ) * ( p2[0] - p3[0] );
    return vcrossu1 * vcrossu2 <= 0;
}


int main(){

    int T;
    cin>>T;
    while (T--) {
        cin>>l1[0]>>l1[1]>>l2[0]>>l2[1];
        if (l1[0]==l2[0]) l2[0]+=EPS2;
        if (l1[1]==l2[1]) l2[1]+=EPS2;

        cin>>r1[0]>>r1[1]>>r2[0]>>r2[1];
        if (r1[0] > r2[0])
            swap(r1[0], r2[0]);
        if (r1[1] > r2[1])
            swap(r1[1], r2[1]);

        r1[0]-=EPS2; r1[1]-=EPS2;
        r2[0]+=EPS2; r2[1]+=EPS2;

        double r3[] = {r1[0], r2[1]};
        double r4[] = {r2[0], r1[1]};

        bool result1 = pointInR(l1[0], l1[1])
                    || pointInR(l2[0], l2[1])
                    || intersec(l1, l2, r1, r3)
                    || intersec(l1, l2, r2, r3)
                    || intersec(l1, l2, r2, r4)
                    || intersec(l1, l2, r1, r4);

        puts(result1 ? "T" : "F");
    }
}
