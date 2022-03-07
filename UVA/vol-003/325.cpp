/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 325
  Name: Identifying Legal Pascal Real Constants
  Problem: https://onlinejudge.org/external/3/325.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    regex re_flo("\\.|e", regex_constants::ECMAScript | regex_constants::icase);
    regex re_num("^\\s*(\\+|\\-)?\\d+(\\.\\d+)?(e(\\+|\\-)?\\d+)?\\s*$",
            regex_constants::ECMAScript | regex_constants::icase);
    regex re_str("^\\s*(.*?)\\s*$", regex_constants::ECMAScript);

    string line;
    while (getline(cin, line)) {
        smatch sm;
        regex_match(line, sm, re_str);
        if (sm[1] == "*") break;

        bool legal = line.find_first_of(".eE")!=string::npos && regex_match(line, re_num);
        cout << sm[1] << (legal ? " is legal.\n" : " is illegal.\n");
    }
}
