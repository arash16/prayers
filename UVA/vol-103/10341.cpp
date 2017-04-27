#include <math.h>
#include <stdio.h>
#include <iostream>
using namespace std;

int p,q,r,s,t,u;
double f(double x) {
    return p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u;
}

int main(){
    double mn, mx, mid, fmn, fmx, fmid;

    while(cin>>p>>q>>r>>s>>t>>u) {
        fmn = f(mn = 0);
        fmx = f(mx = 1);

        if (fmn * fmx <= 0) {
            for (int i=0; i<32; i++) {
                fmid = f(mid = (mn+mx)/2);

                if (fmn * fmid > 0) {
                    mn = mid;
                    fmn = fmid;
                }
                else {
                    mx = mid;
                    fmx = fmid;
                }
            }

            printf("%.4f\n", mid);
        }
        else cout << "No solution\n";
    }
}
