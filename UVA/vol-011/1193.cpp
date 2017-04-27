#include <math.h>
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Range {
    long double s, e;
    Range(long double s, long double e): s(s),e(e) {}
    bool operator < (const Range &r) const {
        return s < r.s;
    }
};


int countmin(const vector<Range> &vec) {
    int cnt = 0;
    for (int i=0; i<vec.size(); cnt++) {
        int j, right = vec[i].e;
        for (j=i+1; j<vec.size() && vec[j].s <= right; j++)
            if (vec[j].e < right)
                right = vec[j].e;
        i = j;
    }
    return cnt;
}


int main(){
    int cse = 1, n;
    long long r, x, y;
    while (cin>>n>>r && (n||r)) {
        bool possible = true;
        vector<Range> vec;
        long long r2 = r*r;
        for (int i=0; i<n; i++) {
            cin>>x>>y;
            if (possible && y <= r) {
                long double dif = sqrt(r2 - y*y);
                vec.push_back(Range(x-dif, x+dif));
            }
            else possible = false;
        }
        sort(vec.begin(), vec.end());

        if (!possible) printf("Case %d: -1\n", cse++);
        else printf("Case %d: %d\n", cse++, countmin(vec));
    }
}
