#include <math.h>
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Range {
    long double s, e;
    Range(long double s, long double e): s(s), e(e) {}
    bool operator < (const Range &r) const {
        return s < r.s;
    }
};


int minchoose(const vector<Range> &vec, long long len) {
    int cnt = 0;
    long double right=0;
    for (int i=0; i<vec.size() && right<len; cnt++) {
        int j, bj=-1;
        for (j=i; j<vec.size() && vec[j].s <= right; j++)
            if (bj<0 || vec[j].e > vec[bj].e)
                bj = j;

        if (bj < 0) return -1;
        right = vec[bj].e;
        i = j;
    }

    return right < len ? -1 : cnt;
}

int main(){
    long long n, l, w, xi, r;
    while (cin>>n>>l>>w) {
        vector<Range> vec;
        long double w24 = w*w/4.0;
        for (int i=0; i<n; i++) {
            cin>>xi>>r;
            if (2*r > w) {
                long double dif = sqrt(r*r - w24);
                vec.push_back(Range(xi-dif, xi+dif));
            }
        }
        sort(vec.begin(), vec.end());

        cout << minchoose(vec, l) << endl;
    }
}
