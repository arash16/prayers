/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 156
  Name: Ananagrams
  Problem: https://onlinejudge.org/external/1/156.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <cstring>
#include <iostream>
#include <string>
#include <map>
using namespace std;

int val(char ch) {
    if (ch>='A' && ch<='Z')
        return ch-'A';

    if (ch>='a' && ch<='z')
        return ch-'a';

    return -1;
}

string encode(char w[]) {
    char cnts[27];
    memset(cnts, 'a', sizeof(cnts));
    int last=-1;
    for (int i=0; w[i]; i++) {
        int v = val(w[i]);
        if (v>=0) cnts[v]++;
        if (v>last) last = v;
    }

    cnts[last+1]=0;
    return string(cnts);
}



int main(){
    int n = 0;
    map<string, int> m;
    map<string, string> w;

    char word[30];
    for(;cin>>word && (word[1] || word[0]!='#'); n++) {
        string e = encode(word);
        m[e] = m[e] + 1;
        w[string(word)] = e;
    }

    for (auto i = w.begin(); i!=w.end(); i++)
        if (m[i->second] == 1)
            cout<< (i->first) <<endl;
}

