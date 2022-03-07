/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 11946
  Name: Code Number
  Problem: https://onlinejudge.org/external/119/11946.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    cin.ignore(100, '\n');

    char ch;
    char D[] = "OIZEASGTBP";
    while ( (ch=getchar()) != EOF )
        putchar(ch>='0' && ch<='9' ? D[ch-'0'] : ch);
}
