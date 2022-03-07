/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 11201
  Name: The problem of the crazy linguist
  Problem: https://onlinejudge.org/external/112/11201.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;


char chargs[2][26] = { "bcdfghjklmnpqrstvwxyz", "aeiou" }, ch1;

double prob[128] = {
    12.53, 1.42, 4.68, 5.86, 13.68, 0.69, 1.01, 0.70, 6.25, 0.44, 0.00, 4.97, 3.15,
    6.71, 8.68, 2.51, 0.88, 6.87, 7.98, 4.63, 3.93, 0.90, 0.02, 0.22, 0.90, 0.52
};

double P[128][8];
int seen[128], C[128][8];
void init(int l=0, double sum=0) {
    C[ch1][l]++;
    P[ch1][l] += sum;
    if (l >= 7) return;

    char *chs = chargs[l & 1];
    for (int i=0; chs[i]; ++i)
        if (seen[chs[i]] < 2) {
            seen[chs[i]]++;
            if (!l) ch1 = chs[i];
            init(l+1, sum + (l+1) * prob[chs[i]]);
            seen[chs[i]]--;
        }
}


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    for (int i='a'; i<='z'; ++i)
        prob[i] = prob[i-'a'];
    init();

    int T;
    cin >> T;
    string str;
    while (T-- && cin >> str) {
        double al = 0;
        for (int i=0; str[i]; ++i)
            al += (i+1) * prob[ str[i] ];

        cout << (al >= P[str[0]][str.length()]/C[str[0]][str.length()] ? "above or equal\n" : "below\n");
    }
}
