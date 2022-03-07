/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 11530
  Name: SMS Typing
  Problem: https://onlinejudge.org/external/115/11530.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
using namespace std;

int num[] = { 1,2,3, 1,2,3, 1,2,3, 1,2,3, 1,2,3, 1,2,3,4, 1,2,3, 1,2,3,4 };

int main() {
    int n;
    cin >> n;
    char line[200];
    cin.getline(line,200);
    for(int cse=1; cse<=n; cse++) {
        cin.getline(line, 200);
        int score = 0;
        for(int i=0; line[i]; i++)
            if (line[i]==' ') score++;
            else score += num[line[i]-'a'];

        printf("Case #%d: %d\n", cse, score);
    }
}
