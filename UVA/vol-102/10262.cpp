/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10262
  Name: Suffidromes
  Problem: https://onlinejudge.org/external/102/10262.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;


bool ispalindrome(const char s[], int len) {
    for (int i=len/2-1; i>=0; --i)
        if (s[i] != s[len-i-1])
            return 0;
    return 1;
}

char* revs(char s[], int len) {
    for (int i=len/2-1; i>=0; --i)
        swap(s[i], s[len-i-1]);
    s[len] = 0;
    return s;
}



int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    char s1[1024], s2[1024];
    while (cin.getline(s1, 1024) && cin.getline(s2, 1024)) {
        if (!strcmp(s1, s2))
            cout << "No solution.\n";

        else {
            int l1 = strlen(s1),
                l2 = strlen(s2);
            bool eq = 1;
            for (int i=0; ; ++i) {
                bool f1 = ispalindrome(s1+i, l1-i),
                     f2 = ispalindrome(s2+i, l2-i);

                if (f1 && !f2)
                    cout << revs(s1, i) << '\n';

                else if (f2 && !f1)
                    cout << revs(s2, i) << '\n';

                else if (f1 && f2 && !eq) {
                    revs(s1, i); revs(s2, i);
                    cout << (strcmp(s1,s2)<0 ? s1 : s2) << '\n';
                }

                else if (i==l2) {
                    if (f1 && f2)
                        cout << (s1[i]=='a' ? 'b' : 'a');
                    cout << revs(s2, i) << '\n';
                }

                else if (i==l1) {
                    if (f1 && f2)
                        cout << (s2[i]=='a' ? 'b' : 'a');
                    cout << revs(s1, i) << '\n';
                }

                else {
                    eq &= s1[i] == s2[i];
                    continue;
                }
                break;
            }
        }
    }
}
