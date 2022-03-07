/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 11743
  Name: Credit Check
  Problem: https://onlinejudge.org/external/117/11743.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
using namespace std;

int dsum(int x) {
    return x<10 ? x : x/10 + x%10;
}

int main(){
    int T;
    cin>>T;
    char line[100];
    cin.getline(line, 100);
    while (T--) {
        cin.getline(line, 100);

        int res=0;
        int cnt=0;
        for (int i=0; line[i]; i++)
            if (line[i] != ' ') {
                int x = line[i]-'0';
                res += cnt&1 ? x : dsum(x<<1);
                cnt++;
            }

        puts(res%10 ? "Invalid" : "Valid");
    }
}
