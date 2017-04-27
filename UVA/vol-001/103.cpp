#include <stdio.h>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int n, d;
int boxes[32][15];
bool mp[32][32];
bool lse(int i, int j) {
    for (int k=0; k<d; k++)
        if (boxes[i][k] >= boxes[j][k])
            return false;

    return true;
}

// -------------------------------------------------

int order[32],
    lpre, pre[32],
    lpost, post[32];

void dfs(int v) {
    if (pre[v]>=0) return;
    pre[v] = lpre++;

    for (int i=0; i<n; i++)
        if (mp[v][i])
            dfs(i);

    order[post[v] = lpost++] = v;
}

void topo() {
    memset(pre, -1, sizeof(pre));
    lpre = lpost = 0;
    for (int i=0; i<n; i++)
        dfs(i);
}

// -------------------------------------------------

int dists[32], befor[32];
void print(int v) {
    if (befor[v] != -1) {
        print(befor[v]);
        cout <<" ";
    }

    cout << v+1;
}

int main() {
    while(cin>>n>>d) {
        for (int i=0; i<n; i++) {
            for (int j=0; j<d; j++)
                cin>>boxes[i][j];

            sort(boxes[i], boxes[i] + d);
        }

        memset(mp, 0, sizeof(mp));
        for (int i=0; i<n; i++)
            for (int j=0; j<n; j++)
                if (i!=j && lse(i, j))
                    mp[i][j] = 1;

        topo();

        int mxs = 0;
        memset(dists, 0, sizeof(dists));

        for (int i=n-1; i>=0; i--) {
            int v = order[i];
            befor[v] = -1;

            for (int j=0; j<n; j++)
                if (mp[j][v] && dists[j]+1 > dists[v]) {
                    dists[v] = dists[j]+1;
                    befor[v] = j;
                }

            if (dists[v] > dists[mxs])
                mxs = v;
        }

        cout<< dists[mxs]+1 <<endl;
        print(mxs);
        cout<<endl;
    }
}

