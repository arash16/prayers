#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <list>
using namespace std;

int n;
char sels[30], chars[30];
int ids[127], seen[30];
vector<string> results;
int adj[30][30];

void dfs(int u, int ind) {
    if (ind == n-1) {
        results.push_back(sels);
        return;
    }

    seen[u] = 1;
    for (int v=1; v<n; v++)
        if (!seen[v]) {
            bool f = true;
            for (int j=0; f && j<ind; j++)
                if (adj[v][ids[sels[j]]])
                    f = false;

            if (f) {
                sels[ind] = chars[v];
                dfs(v, ind+1);
            }
        }
    seen[u] = 0;
}

int main(){
    bool frst=1;
    char c1, c2, l1[100], l2[100];
    while (cin.getline(l1, 100) && cin.getline(l2, 100)) {
        memset(adj, 0, sizeof(adj));
        stringstream sin1(l1);
        for (n=1; sin1>>c1; n++) {
            chars[n] = c1;
            ids[c1] = n;
        }

        sels[n-1] = 0;
        stringstream sin2(l2);
        while (sin2>>c1>>c2)
            adj[ids[c1]][ids[c2]] = 1;

        results.clear();
        dfs(0, 0);
        sort(results.begin(), results.end());

        if (frst) frst=0;
        else putchar('\n');
        for (string s: results)
            cout << s << endl;
    }
}
