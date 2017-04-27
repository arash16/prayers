#include <math.h>
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;


#define MAXN 10001

int n;
double x[MAXN], y[MAXN+1], sx[MAXN];

bool compx(int i, int j) { return x[i] < x[j]; }
bool compy(int i, int j) { return y[i] < y[j]; }

double dist(int i, int j) {
    double xx = x[i]-x[j],
           yy = y[i]-y[j];
    return sqrt(xx*xx + yy*yy);
}

double CP() {
    double mn = 1e300;
    set<int,bool(*)(int,int)> M(compy);
    for (int i=0; i<n; i++) {
        int ind = sx[i];

        y[MAXN] = y[ind] - mn;
        auto it = M.lower_bound(MAXN);
        while (it!=M.end()) {
            int iy = *it;
            if (fabs(x[ind]-x[iy]) > mn) {
                auto it2 = it; it++;
                M.erase(it2);
                continue;
            }
            if (fabs(y[ind]-y[iy]) > mn) break;
            mn = min(mn, dist(ind, iy));
            it++;
        }

        M.insert(ind);
    }
    return mn;
}

int main(){
    while (cin>>n && n) {
        for (int i=0; i<n; i++) {
            cin>>x[i]>>y[i];
            sx[i] = i;
        }
        sort(sx, sx+n, compx);
        double res = CP();
        if (res < 10000)
             printf("%.4lf\n", res);
        else puts("INFINITY");
    }
}
