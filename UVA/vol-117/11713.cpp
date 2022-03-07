/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 11713
  Name: Abstract Names
  Problem: https://onlinejudge.org/external/117/11713.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
using namespace std;

bool isvowel(char ch) {
    return ch=='a' || ch=='e' || ch=='o' || ch=='u' || ch=='i';
}

bool check(char *w1, char *w2) {
    int i;
    for (i=0; w1[i]; i++)
        if (!w2[i]) return 0;
        else {
            bool v1 = isvowel(w1[i]),
                 v2 = isvowel(w2[i]);

            if ((v1^v2) || (!v1 && w1[i]!=w2[i]))
                return false;
        }

    return !w2[i];
}

int main(){
    int n;
    cin>>n;
    while(n--) {
        char w1[30], w2[30];
        cin>>w1>>w2;
        puts(check(w1, w2) ? "Yes" : "No");
    }
}
