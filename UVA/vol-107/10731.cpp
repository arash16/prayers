/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10731
  Name: Test
  Problem: https://onlinejudge.org/external/107/10731.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <list>
using namespace std;

list<int> adj[26];
int pre[26], low[26], pcnt;
bool onstack[26];
stack<int> S;

vector<string> result;
void scc(int u) {
    pre[u] = low[u] = pcnt++;
    onstack[u] = true;
    S.push(u);

    for (int v: adj[u])
        if (pre[v] < 0) {
            scc(v);
            low[u] = min(low[u], low[v]);
        }
        else if (onstack[v])
            low[u] = min(low[u], pre[v]);


    if (pre[u] == low[u]) {
        vector<int> vec;
        for (int v; (v=S.top()) != u; S.pop()) {
            vec.push_back(v);
            onstack[v] = 0;
        }
        S.pop();
        onstack[u] = 0;
        vec.push_back(u);
        sort(vec.begin(), vec.end());

        char rr[100];
        rr[0] = 'A' + vec[0];
        for (int i=1; i<vec.size(); i++) {
            rr[2*i-1] = ' ';
            rr[2*i] = 'A' + vec[i];
        }
        rr[2*vec.size()-1]=0;
        result.push_back(rr);
    }
}

int main(){
    int n, frst=1;
    while (cin>>n && n) {
        if (frst) frst=0;
        else putchar('\n');

        for (int i=0; i<26; i++) {
            adj[i].clear();
            pre[i] = 11111;
        }

        for (int i=0; i<n; i++) {
            char a[6];
            for (int j=0; j<6; j++) {
                cin>>a[j];
                a[j]-='A';
                pre[a[j]]=-1;
            }

            for (int j=0; j<5; j++)
                adj[a[5]].push_back(a[j]);
        }

        pcnt=0;
        result.clear();
        for (int i=0; i<26; i++)
            if (pre[i] < 0)
                scc(i);

        sort(result.begin(), result.end());
        for (string s: result)
            cout << s << endl;
    }
}
