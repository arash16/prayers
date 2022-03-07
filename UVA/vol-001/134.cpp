/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 134
  Name: Loglan-A Logical Language
  Problem: https://onlinejudge.org/external/1/134.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;

static inline std::string &rtrim(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(),
            std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
    return s;
}

// ------------------------------------------------------




int pos, len;
vector<string> tokens;

bool V[128];
bool A() {
    if (pos >= len) return 0;
    string &s = tokens[pos];
    if (s.length()==1 && V[s[0]])
        return ++pos;
    return 0;
}

bool TL(char ch) {
    if (pos >= len) return 0;
    string &s = tokens[pos];
    if (s.length()==2 && V[s[1]] && s[0]==ch)
        return ++pos;
    return 0;
}
bool MOD() { return TL('g'); }
bool BA() { return TL('b'); }
bool DA() { return TL('d'); }
bool LA() { return TL('l'); }

bool NAM() {
    if (pos >= len) return 0;
    string &s = tokens[pos];
    if (!V[s[s.length()-1]])
        return ++pos;
    return 0;
}
bool PREDA() {
    if (pos >= len) return 0;
    string &s = tokens[pos];
    if (s.length() == 5 && !V[s[0]] && !V[s[3]] && V[s[4]] && V[s[1]]!=V[s[2]])
        return ++pos;
    return 0;
}
bool predstring() {
    if (pos >= len || !PREDA())
        return 0;
    while (PREDA());
    return 1;
}
bool verbpred() {
    int b = pos;
    if (MOD() && predstring())
        return 1;
    pos = b;
    return 0;
}
bool predname() {
    int b = pos;
    if (NAM() || (LA() && predstring()))
        return 1;
    pos = b;
    return 0;
}
bool statement() {
    int b = pos;
    if (predname() && verbpred()) {
        predname();
        return 1;
    }
    pos = b;
    return 0;
}
bool preds() {
    int b = pos;
    if (predstring()) {
        int bb;
        do { bb = pos; }
        while (A() && predstring());
        pos = bb;
        return 1;
    }
    pos = b;
    return 0;
}
bool predclaim() {
    int b = pos;
    if (DA() && preds())
        return 1;

    pos = b;
    if (predname() && BA() && preds())
        return 1;

    pos = b;
    return 0;
}
bool sentence() {
    int b = pos;
    if (statement()) return 1;

    pos = b;
    if (predclaim()) return 1;

    pos = b;
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    V['a']=V['e']=V['i']=V['o']=V['u']=1;

    string line, exline;
    while (getline(cin, line) && line[0]!='#') {
        line = rtrim(line);
        while (line[line.length()-1] != '.') {
            getline(cin, exline);
            line += " " + exline;
            line = rtrim(line);
        }

        //cout << line << endl;
        tokens.clear();
        for (int i=0, j=0; i<line.length(); ++i)
            if (!isalpha(line[i])) {
                if (i != j)
                    tokens.push_back(line.substr(j, i-j));
                j = i+1;
            }

        pos = 0;
        len = tokens.size();
        cout << (sentence() && pos==tokens.size() ? "Good\n" : "Bad!\n");
    }
}
