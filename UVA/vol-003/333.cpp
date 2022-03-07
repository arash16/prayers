/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 333
  Name: Recognizing Good ISBNs
  Problem: https://onlinejudge.org/external/3/333.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;


bool iswhite(char ch) {
    switch(ch) {
        case ' ':
        case '\t':
        case '\r':
        case '\n':
        return 1;
    }
    return 0;
}

bool check(char isbn[]) {
    int digits[20], l = 0;
    for (int i=0; isbn[i]; ++i)
        if (isbn[i] == '-' || iswhite(isbn[i])) continue;
        else if (isbn[i]=='X' && l == 9)
            digits[l++] = 10;
        else if (isdigit(isbn[i]))
            digits[l++] = isbn[i]-'0';
        else return 0;

    if (l != 10) return 0;

    int r = digits[0];
    for (int i=1; i<10; ++i)
        r += (digits[i] += digits[i-1]);
    return r % 11 == 0;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    string lin;
    while (getline(cin, lin)) {
        char isbn[90] = {};
        int s = 0, e = lin.length()-1;
        while (iswhite(lin[s])) ++s;
        while (iswhite(lin[e])) --e;
        for (int i=s; i<=e; ++i)
            isbn[i-s] = lin[i];

        cout << isbn << (check(isbn) ? " is correct.\n" : " is incorrect.\n");
    }
}
