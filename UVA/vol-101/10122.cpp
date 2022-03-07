/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10122
  Name: Mysterious Mountain
  Problem: https://onlinejudge.org/external/101/10122.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <math.h>
#include <stdio.h>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define EPS 1e-9
#define MAXN 110


int abs(int x) {
    return x<0 ? -x : x;
}

struct P {
    double x, y;

    P() {};
    P(double q, double w) : x(q), y(w) {};

    bool operator<(const P &p) const {
        return x<p.x || (x==p.x && y<p.y);
    }
};

bool lineSegIntersect(P a, P b, P c, P d) {
    double ucrossv1 = (b.x - a.x)*(c.y - a.y) - (b.y - a.y)*(c.x - a.x);
    double ucrossv2 = (b.x - a.x)*(d.y - a.y) - (b.y - a.y)*(d.x - a.x);
    if (ucrossv1*ucrossv2 > 0) return false;

    double vcrossu1 = (d.x - c.x)*(a.y - c.y) - (d.y - c.y)*(a.x - c.x);
    double vcrossu2 = (d.x - c.x)*(b.y - c.y) - (d.y - c.y)*(b.x - c.x);
    return vcrossu1*vcrossu2 <= 0;
}


// ----------------------------------------------------------------------------


int n, maxEp, minEp,
    c[MAXN], w[MAXN], s[MAXN];
P coords[MAXN];

int memo[MAXN][1005];
bool collides(int ep, int s) {
    if (memo[ep][s] != -1)
        return memo[ep][s];

    if (fabs(coords[ep].x-s) < EPS)
        return memo[ep][s]=0;

    P p1 = P(coords[ep].x, coords[ep].y -EPS),
      p2 = P(s, -EPS);

    for (int i=ep; i<n+1 && coords[i].x<s; i++)
        if (lineSegIntersect(coords[i], coords[i+1], p1, p2))
            return memo[ep][s] = 1;

    for (int i=ep; i>0 && coords[i].x>s; i--)
        if (lineSegIntersect(coords[i-1], coords[i], p1, p2))
            return memo[ep][s] = 1;

    return memo[ep][s] = 0;
}

double moveTime(int ep, int p, int cu) {
    double d = abs(s[p] - cu);
    double x = fabs(coords[ep].x - cu);
    return d/w[p] + sqrt(x*x + coords[ep].y*coords[ep].y)/c[p];
}

double dist(int ep, int p) {
    if (coords[ep].y < EPS)
        return fabs(s[p] - coords[ep].x) / max(w[p], c[p]);

    int cu;
    if (w[p] > c[p]) {
        double opt = c[p]*coords[ep].y / sqrt((double)w[p]*w[p]-c[p]*c[p]);
        if (s[p] > coords[ep].x)
            cu = ceil(min(coords[ep].x + opt, (double) s[p]));
        else cu = floor(max(coords[ep].x - opt, (double) s[p]));
    }
    else cu = s[p];
    if (cu > maxEp) cu = maxEp;
    if (cu < minEp) cu = minEp;

    int step = cu > coords[ep].x ? -1 : 1;
    while (cu>=minEp && cu<=maxEp && collides(ep, cu))
        cu += step;

    if (cu > maxEp) cu = maxEp;
    if (cu < minEp) cu = minEp;

    return min(moveTime(ep, p, cu), moveTime(ep, p, cu + step));
}

// ---------------------------------------------------------------------

struct Trip {
    int i, j;
    double d;

    Trip() {};
    Trip(int a, int b, double w) : i(a), j(b), d(w) { };
    bool operator<(const Trip &t) const {
        return d<t.d;
    }
};




bool graph[MAXN][MAXN], seen[MAXN],
     hasL[MAXN], hasR[MAXN];
int matchR[MAXN];
bool bpm(int u) {
    for (int v = 0; v < n; v++)
        if (graph[u][v]) {
            if (seen[v]) continue;
            seen[v] = true;

            if (matchR[v] < 0 || bpm(matchR[v])){
                matchR[v] = u;
                return true;
            }
        }
    return false;
}

int maxBpm() {
    for (int i=0; i<n; i++) matchR[i] = -1;

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j=0; j<n; j++)
            seen[j]=0;

        if (bpm(i)) cnt++;
    }
    return cnt;
}




int main(){
    vector<Trip> trips;
    while (cin>>n && n) {
        trips.clear();

        int maxX = maxEp = 0;
        minEp = 10000;
        for (int i=0; i<n+2; i++) {
            cin >> coords[i].x >> coords[i].y;
            if (coords[i].x>maxX) maxX = maxEp = coords[i].x;
            if (coords[i].x<minEp) minEp = coords[i].x;
        }

        for (int i=0; i<n; i++) {
            cin >> c[i] >> w[i] >> s[i];
            if (s[i]>maxX) maxX = s[i];
        }

        for (int i=0; i<n+2; i++)
            for (int j=0; j<=maxX; j++)
                memo[i][j] = -1;

        for (int i=0; i<n; i++)
            for (int j=0; j<n; j++)
                trips.push_back( Trip(i, j, dist(i+1, j)) );


        sort(trips.begin(), trips.end());

        memset(graph, 0, sizeof(graph));
        memset(hasL, 0, sizeof(hasL));
        memset(hasR, 0, sizeof(hasR));

        int i, c=0;
        for (i=0; c<2*n; i++) {
            int a = trips[i].i,
                b = trips[i].j;

            graph[a][b] = true;

            // lower bound, less maxBpm calls
            if (!hasL[a]) c += (hasL[a]=1);
            if (!hasR[b]) c += (hasR[b]=1);
        }

        for (; i<n*n && maxBpm()<n; i++)
            graph[trips[i].i][trips[i].j] = true;

        printf("%.2f\n", round(100*trips[i-1].d)/100.0);
    }
}
