/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10298
  Name: Power Strings
  Problem: https://onlinejudge.org/external/102/10298.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
    char line[1000002];
    for (;;) {
        line[0] = getchar();
        if (line[0] == '.') break;

        int i, n = 1;
        for (i=1; (line[i]=getchar()) != '\n'; i++)
            while (line[i%n] != line[i])
                n++;
        if (i % n) n = i;

        cout << i/n << endl;
    }
}
