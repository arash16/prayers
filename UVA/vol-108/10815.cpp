/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10815
  Name: Andy's First Dictionary
  Problem: https://onlinejudge.org/external/108/10815.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
#include <set>
#include <string>
using namespace std;


char tolower(char ch) {
    return ch>='a' && ch<='z' ? ch-32 : ch;
}


int main(){
    set<string> dic;
    char ch, word[202];
    int i=0;
    while ((ch=tolower(getchar())) != EOF) {
        if (ch>='a' && ch<='z')
            word[i++] = ch;

        else if (i > 0) {
            word[i] = 0;
            dic.insert(word);
            i = 0;
        }
    }

    for (auto it=dic.begin(); it!=dic.end(); it++)
        cout << (*it) << endl;
}
