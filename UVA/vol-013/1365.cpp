/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 1365
  Name: Wild West
  Problem: https://onlinejudge.org/external/13/1365.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

typedef unsigned long long Long;

#define MAXN 100017
int x[MAXN], y[MAXN], z[MAXN], ord[MAXN];
bool lessz (int i, int j) { return z[i] > z[j]; }
bool lessxy(int i, int j) { return x[i] != x[j] ? x[i] < x[j] : y[i] > y[j]; }

set<int, bool(*)(int,int)> rarea(lessxy);
Long ainsert(int p) {
    int a=x[p], b=y[p];
    Long sum = a*b;
    if (rarea.size()) {
        int my = 0;
        auto it = rarea.lower_bound(p);
        if (it == rarea.end()) --it;
        else if (x[*it]==a && y[*it]==b) return 0;

        int j = *it;
        for (; it!=rarea.begin() && y[j] <= b; j=*it) {
            sum -= (y[j] - my) * min(x[j], a);
            my = y[j];

            if (x[j] <= a) {
                auto it2 = it; --it;
                rarea.erase(it2);
            }
            else --it;
        }
        sum -= (min(b, y[j]) - my) * min(x[j], a);
        if (x[j] <= a && y[j] <= b)
            rarea.erase(it);
    }

    if (sum > 0)
        rarea.insert(p);
    return sum;
}

int main() {
    int n, m;
    while (scanf("%d%d", &n, &m)==2 && (n||m)) {
        for (int i=0; i<n; i++) {
            scanf("%d%d%d", x+i, y+i, z+i);
            ord[i] = i;
        }
        sort(ord, ord+n, lessz);

        rarea.clear();
        Long sum = Long(m) * m * m;
        for (int i=0; i<n; ++i) {
            int j = ord[i];
            sum -= z[j] * ainsert(j);
        }
        printf("%llu\n", sum);
    }
}
