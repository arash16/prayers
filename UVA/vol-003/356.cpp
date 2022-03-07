/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 356
  Name: Square Pegs And Round Holes
  Problem: https://onlinejudge.org/external/3/356.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int n;
    bool frst = 1;
    while (cin >> n) {
        if (frst) frst = 0;
        else printf("\n");

        int ic = 0,
            oc = 0;
        double n2 = (2*n-1)/2.0; n2 *= n2;
        for (int i=0; i<n; ++i)
            for (int j=0; j<n; ++j) {
                bool bl = i*i + j*j <= n2;
                bool tr = (i+1)*(i+1) + (j+1)*(j+1) <= n2;
                if (bl && tr) ic++;
                else if (bl && !tr) oc++;
                else break;
            }

        printf("In the case n = %d, %d cells contain segments of the circle.\n", n, oc*4);
        printf("There are %d cells completely contained in the circle.\n", ic*4);
    }
}
