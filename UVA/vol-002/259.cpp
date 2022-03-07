/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 259
  Name: Software Allocation
  Problem: https://onlinejudge.org/external/2/259.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> adj[26];
int match[10],X[26];
bool seen[10];
bool bpm(int u) {
    for (int v: adj[u])
        if (!seen[v]) {
            seen[v] = true;
            if (match[v] == -1 || bpm(match[v])) {
                match[v] = u;
                return true;
            }
        }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    string line;
    while (1) {
        for (int i=0; i<26; ++i)
            adj[i].clear(),
            X[i] = 0;

        int kk=0;
        while (getline(cin, line) && line[0]) {
            ++kk;
            int u = line[0]-'A';
            X[u] += line[1]-'0';
            for (int i=3; i<line.length()-1; ++i)
                if (line[i]!=' ')
                    adj[u].push_back(line[i]-'0');
        }
        if (!kk) return 0;

        memset(match, -1, sizeof(match));
        for (int i=0; i<26; ++i)
            for (int j=0; j<X[i]; ++j) {
                memset(seen, 0, 10);
                if (!bpm(i)) {
                    cout << "!\n";
                    goto fin;
                }
            }

        for (int i=0; i<10; ++i)
            cout << char(match[i]<0 ? '_' : match[i]+'A');
        cout << '\n';

        fin:;
    }
}
