/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 347
  Name: Run
  Problem: https://onlinejudge.org/external/3/347.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;

bool seen[100];
int isrun(char s[], int len) {
    seen[0] = 1;
    memset(seen+1, 0, 10);
    for (int i=0; i<len; ++i) {
        if (seen[s[i]]) {
            while (seen[s[i]+1])
                ++s[i];
            return i;
        }
        seen[s[i]] = 1;
    }

    memset(seen, 0, len);
    int cnt=0, i;
    for (i=0; !seen[i]; i=(i+s[i]) % len) {
        seen[i] = 1;
        ++cnt;
    }
    if (cnt == len && !i) return -1;

    for (int i=len-1; i>=0; --i)
        if (seen[i])
            return i;
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int cse=1, l;
    char num[21];
    while (cin>>num && (num[1] || num[0]!='0')) {
        for (l=0; num[l]; ++l)
            num[l] -= '0';

        for (;;) {
            int er = isrun(num, l);
            if (er < 0) break;

            while (er && num[er]>=9) --er;
            if (!er && num[0]==9) {
                num[0] = 0;
                ++l;
            }

            ++num[er];
            for (int i=er+1, k=1; i<l; ++i)
                num[i] = k++;
        }

        num[l] = 0;
        for (int i=0; i<l; ++i)
            num[i]+='0';

        cout << "Case " << (cse++) << ": " << num << endl;
    }
}
