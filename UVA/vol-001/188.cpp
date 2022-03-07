/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 188
  Name: Perfect Hash
  Problem: https://onlinejudge.org/external/1/188.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

unsigned int w[20], n;
unsigned int nextC(int c) {
    for (int d=1; d<n; d++)
        for (int i=0; i<n-d; i++) {
            int j = i + d;
            if ( (c/w[i])%n == (c/w[j])%n )
                return min( (c/w[i]+1)*w[i], (c/w[j]+1)*w[j] );
        }
    return 0;
}

int main(){
    char line[200];
    while (cin.getline(line, 200) && line[0]) {
        n = 0;
        int x = 0;
        for (int i=0; line[i]; i++)
            if (line[i] == ' ') {
                if (x) w[n++] = x;
                x = 0;
            }
            else x = (x<<5) + line[i]-'a'+1;
        if (x) w[n++] = x;
        sort(w, w+n);

        unsigned int c;
        for (unsigned int nc=w[n-2]; nc; nc=nextC(nc))
            c = nc;

        puts(line);
        printf("%u\n\n", c);
    }
}
