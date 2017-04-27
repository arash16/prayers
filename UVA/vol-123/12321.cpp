#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Range {
    int s, e;
    Range(int s, int e): s(s),e(e) {}
    bool operator < (const Range& r) const {
        return s < r.s;
    }
};

int minchoose(const vector<Range> &vec, int len) {
    int cnt=0, right=0;
    for (int i=0; right<len && i<vec.size(); cnt++) {
        int j, bj=-1;
        for (j=i; j<vec.size() && vec[j].s<=right; j++)
            if (bj<0 || vec[j].e>vec[bj].e)
                bj = j;

        if (bj < 0) return -1;
        right = vec[bj].e;
        i = j;
    }
    return right < len ? -1 : cnt;
}

int main(){
    int l, g, xi, ri;
    while (cin>>l>>g && (l||g)) {
        vector<Range> vec;
        for (int i=0; i<g; i++) {
            cin >> xi >> ri;
            vec.push_back(Range(xi-ri, xi+ri));
        }
        sort(vec.begin(), vec.end());

        int m = minchoose(vec, l);
        if (m >= 0) m = g-m;
        cout << m << endl;
    }
}
