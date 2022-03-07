/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 11572
  Name: Unique Snowflakes
  Problem: https://onlinejudge.org/external/115/11572.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <unordered_map>
using namespace std;

bool seen[1000001];
int main(){
    int T, n, X[1000001], y;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        unordered_map<int, int> ids;
        int idcnt = 0;

        int mx=0, i;
        for (int j=i=0; j<n; ++j) {
            scanf("%d", &y);
            auto it = ids.find(y);
            if (it == ids.end())
                seen[X[j] = ids[y] = idcnt++] = 1;

            else {
                X[j] = it->second;
                if (seen[X[j]]++) {
                    for (;i<j && X[i]!=X[j]; ++i)
                        seen[X[i]] = 0;
                    ++i;
                }
            }

            mx = max(mx, j-i+1);
        }
        printf("%d\n", mx);
    }
}
