#include <bits/stdc++.h>
using namespace std;

string keywords[] = {
    "IF", "THEN", "ELSE",
    "AND", "OR", "NULL",
    "MY", "YOUR", "LAST", "1", "2",
    "TRADE", "CHEAT"
};

int skips[127];
int pos;
string tokens;


int Mem[2][2], cu;
int evalMemory() {
    char c = tokens[pos];
    pos += skips[c] + skips['L'];
    char n = tokens[pos++] - '0' - 1;

    return Mem[c=='M' ? cu : 1-cu][n];
}
bool evalCond() {
    int m = evalMemory();
    char ch = tokens[pos++];

    char tc = tokens[pos];
    int tst = tc == 'N' ? 0
            : tc == 'T' ? 1
            : 2;
    pos += skips[tc];
    return ch=='=' ? m == tst : m != tst;
}
bool evalCondition() {
    bool result = evalCond();
    while (1) {
        char ch = tokens[pos];
        if (ch != 'A' && ch != 'O')
            return result;

        pos += skips[ch];
        if (ch == 'A')
             result &= evalCondition();
        else result |= evalCondition();
    }
}
int evalStatement() {
    char ch = tokens[pos];
    pos += skips[ch];
    switch (ch) {
        case 'T': return 1;
        case 'C': return 2;
        case 'I':
            bool cond = evalCondition();
            pos += 4; // THEN
            int t1 = evalStatement();
            pos += 4; // ELSE
            int t2 = evalStatement();
            return cond ? t1 : t2;
    }
    throw "Syntax Error";
}


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    for (int i=0; i<13; ++i)
        skips[keywords[i][0]] = keywords[i].length();


    vector<string> programs;
    string line, str;
    while (cin >> str) {
        line += str;
        if (line[line.length()-1] == '.') {
            programs.push_back(line);
            line = "";
        }
    }

    int scores[20] = {};
    for (int i=0; i<programs.size(); ++i)
        for (int j=0; j<i; ++j)
            if (i!=j) {
                memset(Mem, 0, sizeof(Mem));

                for (int k=0; k<10; ++k) {
                    cu = 0;
                    pos = 0;
                    tokens = programs[i];
                    int r1 = evalStatement();

                    cu = 1;
                    pos = 0;
                    tokens = programs[j];
                    int r2 = evalStatement();

                    Mem[0][1] = Mem[0][0];
                    Mem[0][0] = r1;
                    Mem[1][1] = Mem[1][0];
                    Mem[1][0] = r2;

                    if (r1==1 && r2==1)
                        ++scores[i],
                        ++scores[j];

                    else if (r1==2 && r2==1)
                        scores[i] += 2,
                        scores[j] -= 2;

                    else if (r1==1 && r2==2)
                        scores[i] -= 2,
                        scores[j] += 2;

                    else
                        --scores[i],
                        --scores[j];
                }
            }

    for (int i=0; i<programs.size(); ++i)
        printf("%3d\n", scores[i]);
}
