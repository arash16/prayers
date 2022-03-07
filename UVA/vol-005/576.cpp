/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 576
  Name: Haiku Review
  Problem: https://onlinejudge.org/external/5/576.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <cstring>
#include <iostream>
using namespace std;

bool isvowel(char c) {
    return c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='y';
}


int haiku[] = {5,7,5};
int check(char *line) {
    int j=-1;
    for (int i=0; i<3; i++) {
        int c=0;
        bool last=0;
        for (j++; line[j] && line[j]!='/'; j++)
            if (!isvowel(line[j])) last=0;
            else if (!last) { c++; last=1; }

        if (c != haiku[i])
            return i+1;
    }
    return 0;
}

char results[] = "Y123";
int main(){
    char line[500];
    while (cin.getline(line, 500) && strcmp(line, "e/o/i")) {
        putchar(results[check(line)]);
        putchar('\n');
    }
}
