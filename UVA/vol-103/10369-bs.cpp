#include <math.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <set>
using namespace std;

#define MAXN 501

int n;
int X[MAXN], Y[MAXN];
double D[MAXN][MAXN];

double dii;
bool seen[MAXN];

void dfs(int u) {
    if (seen[u]) return;
    seen[u] = 1;

    for (int i=0; i<n; i++)
        if (i!=u && D[i][u] <= dii)
            dfs(i);
}

int countCc(double d) {
    for (int i=0; i<n; i++)
        seen[i]=0;

     dii=d;
     int cnt=0;
     for (int i=0; i<n; i++)
         if (!seen[i]) {
             dfs(i);
             cnt++;
         }

     return cnt;
}


int main(){
    int T, s;
    cin>>T;
    while (T--) {
        cin >> s >> n;

        set<double> spd;
        for (int i=0; i<n; i++) {
            cin>>X[i]>>Y[i];
            for (int j=0; j<i; j++) {
                double xx = X[i]-X[j],
                       yy = Y[i]-Y[j];

                spd.insert(D[i][j] = D[j][i] = sqrt(xx*xx+yy*yy));
            }
        }

        vector<double> posd(spd.rbegin(), spd.rend());
        int lo=0, hi=posd.size();
        while (lo <= hi) {
            int mid = (lo+hi+1)>>1;
            if (countCc(posd[mid]) <= s)
                lo = mid+1;
            else
                hi = mid-1;
        }

        printf("%.2f\n", posd[lo-1]);
    }
}
