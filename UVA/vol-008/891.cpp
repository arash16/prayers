#include <bits/stdc++.h>
using namespace std;

inline int readchar(bool skip=true) {
    const int N = 4194304;
    static char buf[N];
    static char *p = buf, *end = buf;
    bool fin = 0;
    if (fin) return EOF;
    if (p == end) {
        if ((end = buf + fread(buf, 1, N, stdin)) == buf) {
            fin = 1;
            return EOF;
        }
        p = buf;
    }
    int result = *p;
    if (skip) ++p;
    return result;
}
inline bool isdigit(char ch) { return ch>='0' && ch<='9'; }
inline int readUInt() {
    char ch;
    unsigned int r=0;
    while (!isdigit(ch=readchar()))
        if (ch == EOF) return EOF;
    r = ch-'0';
    while (isdigit(ch=readchar()))
        r = (r<<3) + (r<<1) + ch-'0';

    while (ch != '\n')
        ch = readchar();
    return r;
}
inline int readLine(char *str) {
    int len=0;
    char ch;
    while ((ch=readchar())!='\n' && ch!=EOF)
        str[len++] = ch;

    str[len] = 0;
    if (ch == EOF && !len) return EOF;
    return len;
}
// ------------------------------------------------------------------------------------------

struct Triplet {
    int w, h1, h2;
    Triplet(){}
    Triplet(int w, int h1, int h2):w(w),h1(h1),h2(h2){}
};

struct Token {
    char ch;
    int len;
    Token(char ch, int len=0):ch(ch),len(len){}
};


vector<Token> tokens;
int pos;
Triplet evaluate() {
    Token &s = tokens[pos++];
    Triplet r1, r2;
    switch (s.ch) {
        case '"':
            return Triplet(s.len + 6, 2, 1);

        case '(':
            r1 = evaluate();
            r2 = evaluate();
            ++pos;
            return Triplet(r1.w + r2.w, max(r1.h1, r2.h1), max(r1.h2, r2.h2));

        case '{':
            r1 = evaluate();
            r2 = evaluate();
            ++pos;
            return Triplet(max(r1.w, r2.w) + 4, r1.h1, r1.h2 + 1 + r2.h1 + r2.h2);

        case '[':
            r1 = evaluate();
            ++pos;
            return Triplet(r1.w + 4, r1.h1 + 1, r1.h2);
    }
    throw "Syntax Error";
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    char line[1000000];
    int T = readUInt();
    while (T--) {
        int len = readLine(line);
        tokens.clear();
        for (int i=0; i<=len; ++i)
            if (line[i] == '"') {
                int j = i+1;
                while (line[j] != '"') ++j;
                tokens.push_back(Token('"', j-i+1));
                i = j;
            }
            else if (line[i] != ' ' && line[i] != '\t')
                tokens.push_back(Token(line[i]));

        pos = 0;
        Triplet result = evaluate();
        cout << result.w+4 << 'x' << result.h1 + result.h2 << '\n';
    }
}
