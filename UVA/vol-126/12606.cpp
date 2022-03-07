/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 12606
  Name: Evaluating Logic Expressions
  Problem: https://onlinejudge.org/external/126/12606.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;

bool readBool() {
    string str;
    cin >> str;
    return str=="true";
}

// ----------------------------------------------------------

char valNames[3][10] = {
    "unknown",
    "false",
    "true"
};

int un, bn, pos, vars[128];
bool TBL[202][2][2], isal[128], isup[128];
map<string, int> ids;
vector<string> tokens;

int readTbl(int oid, int r1, int r2) {
    #define T TBL[oid]
    if (r1 < 0 && r2 < 0)
        return T[0][0]==T[0][1] && T[1][0]==T[1][1] && T[0][0]==T[1][0] ? T[0][0] : -1;

    if (r1 < 0)
        return T[0][r2]==T[1][r2] ? T[0][r2] : -1;

    if (r2 < 0)
        return T[r1][0]==T[r1][1] ? T[r1][0] : -1;

    return T[r1][r2];
}

int evalExpression() {
    string &s = tokens[pos++];
    if (s[0] != '(')
        return vars[s[0]];

    int r1, r2, oid;
    if (isup[tokens[pos][0]]) {
        oid = ids[tokens[pos++]];
        r2 = evalExpression();
        r1 = 0;
    }
    else {
        r1 = evalExpression();
        oid = ids[tokens[pos++]];
        r2 = evalExpression();
    }

    if (tokens[pos++][0] != ')')
        throw "Syntax Error";

    return readTbl(oid, r1, r2);
}


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    for (int i=0; i<26; ++i)
        isal[i+'a'] = isal[i+'A'] = isup[i+'A'] = 1;

    string str;
    for (int cse=1; cin >> un >> bn && (un>=0 && bn>=0); ++cse) {
        ids.clear();
        for (int i=0; i<un; ++i) {
            cin >> str;
            ids[str] = i;
            TBL[i][0][0] = readBool();
            TBL[i][0][1] = readBool();
        }
        for (int k=0; k<bn; ++k) {
            cin >> str;
            ids[str] = un+k;
            for (int i=0; i<2; ++i) {
                for (int j=0; j<2; ++j)
                    TBL[un+k][i][j] = readBool();
            }
        }

        cin.ignore(100, '\n');
        getline(cin, str);
        tokens.clear();
        for (int i=0, j=0; i<=str.length(); ++i)
            if (!isal[str[i]]) {
                if (j < i)
                    tokens.push_back(str.substr(j, i-j));

                if (str[i] == '(' || str[i] == ')')
                    tokens.push_back(str.substr(i, 1));

                j = i+1;
            }

        memset(vars, -1, sizeof(vars));
        while (cin >> str && str!="*")
            vars[str[0]] = readBool();

        pos = 0;
        cout << "Case " << cse << ": " << valNames[evalExpression()+1] << '\n';
    }
}
