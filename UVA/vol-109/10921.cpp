/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10921
  Name: Find the Telephone
  Problem: https://onlinejudge.org/external/109/10921.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
using namespace std;

int codes[] = { 2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,7,8,8,8,9,9,9,9 };

int main() {
    char ch;
    while (scanf("%c", &ch) == 1) {
        if (ch >= 'A' && ch <= 'Z')
            cout << codes[ch - 'A'];
        else if (ch >= 'a' && ch <= 'z')
            cout << codes[ch - 'a'];
        else cout << ch;
    }
    if (ch != '\n') cout << endl;
}
