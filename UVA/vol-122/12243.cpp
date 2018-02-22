#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    string line, word;
    while (getline(cin, line)) {
        stringstream sin(line);
        sin >> word;
        if (word == "*") break;
        char ch=toupper(word[0]);
        bool t=1;
        while (t && sin >> word)
            t = t && toupper(word[0]) == ch;

        cout << (t ? "Y\n" : "N\n");
    }
}
