#include <math.h>
#include <stdio.h>
#include <iostream>
using namespace std;

int px, py;
int count (int tk, int cx, int cy) {
    int k = tk >> 1,
        c = (px>=cx-k && px<=cx+k &&
             py>=cy-k && py<=cy+k) ? 1:0;
    if (k <= 1) return c;

    if (px < cx)
        if (py < cy)
             return c + count(k, cx-k, cy-k);
        else return c + count(k, cx-k, cy+k);
    else if (px > cx)
        if (py < cy)
             return c + count(k, cx+k, cy-k);
        else return c + count(k, cx+k, cy+k);
    return c;
}

int main(){
    int k;
    while (cin>>k>>px>>py && (k||px||py))
        printf("%3d\n", count(k<<1, 1024, 1024));
}
