/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 11475
  Name: Extend to Palindrome
  Problem: https://onlinejudge.org/external/114/11475.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;


bool isPal(char s[], int l) {
    for (int i=0, hl=l/2; i<=hl; ++i)
        if (s[i] != s[l-i-1])
            return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    char inp[286000];
    while (cin >> inp) {
        int len = strlen(inp);
        for (int i=0; i<len; ++i)
            if (isPal(inp+i, len-i)) {
                inp[len += i] = 0;
                for (int j=0; j<i; ++j)
                    inp[len-j-1] = inp[j];
                cout << inp << endl;
                break;
            }
    }
}
