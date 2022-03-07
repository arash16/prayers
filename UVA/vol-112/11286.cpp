/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 11286
  Name: Conformity
  Problem: https://onlinejudge.org/external/112/11286.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    int n, x, z[5];
    while (scanf("%d", &n)==1 && n) {
        unordered_map<long long, int> freq;
        vector<long long> vec;

        int mx = 0;
        for (int i=0; i<n; ++i) {
            scanf("%d%d%d%d%d", z,z+1,z+2,z+3,z+4);
            sort(z, z+5);
            long long y = 0;
            for (int j=0; j<5; ++j)
                y = y*400 + z[j]-100;

            mx = max(mx, ++freq[y]);
            vec.push_back(y);
        }

        int cnt = 0;
        for (long long y: vec)
            if (freq[y] == mx)
                ++cnt;

        printf("%d\n", cnt);
    }
}
