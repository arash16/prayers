/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10305
  Name: Ordering Tasks
  Problem: https://onlinejudge.org/external/103/10305.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

vector<int> adj[101], order;
int pre[101], last;

void traverse(int v) {
    if (pre[v]) return;
    pre[v] = ++last;
    for (int i = adj[v].size() - 1; i >= 0; i--)
        traverse(adj[v][i]);

    order.push_back(v);
}


int main() {

    int n, m, x, y;
    while ((cin >> n >> m) && n) {
        for (int i = 1; i <= n; i++) {
            adj[i].clear();
            pre[i] = 0;
        }

        for (int i = 0; i < m; i++) {
            cin >> x >> y;
            adj[y].push_back(x);
        }


        last = 0;
        order.clear();
        for (int i = 1; i <= n; i++)
            traverse(i);

        for (int i = 0; i < order.size() - 1; i++)
            cout << order[i] << " ";
        cout << order[order.size() - 1] << endl;
    }
}