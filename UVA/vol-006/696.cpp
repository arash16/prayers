#include <math.h>
#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
    int n, m, res;
    while (cin>>n>>m && (n||m)) {
        int a=min(n, m), b=max(n, m);
        if (a==1) res = b;
        else if (a==2)
            res = b%4==1 ? 4*(b>>2)+2 : 4*((b-1)>>2)+4;
        else res = (n*m+1)>>1;
        printf("%d knights may be placed on a %d row %d column board.\n", min(n*m, max(4, res)), n, m);
    }
}
