#include <math.h>
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


const int MAXN = 10001;

int n, sx[MAXN];
double x[MAXN], y[MAXN];
bool compx(int i, int j) { return x[i] < x[j]; }
bool compy(int i, int j) { return y[i] < y[j]; }

double dist(int i, int j) {
    double xx = x[i] - x[j],
           yy = y[i] - y[j];
    return sqrt(xx*xx + yy*yy);
}

double CP(int s, int e) {
    int size = e-s;
    if (size <= 1)
        return 1e300;
    else if (size == 2)
        return dist(sx[s], sx[s+1]);

    int mid = (s+e)>>1;
    double xmd = x[sx[mid]];
    double del = min(CP(s, mid), CP(mid, e));


    vector<int> sy;
    for (int i=mid-1; i>=s && xmd-x[sx[i]] < del; i--)
        sy.push_back(sx[i]);
    for (int i=mid; i<e && x[sx[i]]-xmd < del; i++)
        sy.push_back(sx[i]);
    sort(sy.begin(), sy.end(), compy);

    for (int i=sy.size()-1; i>=0; i--) {
        double yi = y[sy[i]];
        for (int j=i-1; j>=0 && yi-y[sy[j]]<del; j--)
            del = min(del, dist(sy[i], sy[j]));
    }

    return del;
}



int main(){
    while (cin>>n && n) {
        for (int i=0; i<n; i++) {
            cin >> x[i] >> y[i];
            sx[i]=i;
        }
        sort(sx, sx+n, compx);
        double res = CP(0, n);

        if (res < 10000)
             printf("%.4lf\n", res);
        else puts("INFINITY");
    }
}
