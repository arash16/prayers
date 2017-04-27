#include <stdio.h>
#include <iostream>
#include <list>
using namespace std;

struct Edge {
    int u, v, d;
    Edge(int u, int v, int d): u(u),v(v),d(d) {}
};

int main(){
    int n, x, d[101];

    while (cin>>n) {
        list<Edge> eds;

        for (int i=0; i<n; i++) {
            d[i] = 1<<30;
            for (int j=0; j<i; j++) {
                char y[20];
                cin >> y;
                if (y[0] != 'x') {
                    sscanf(y, "%d", &x);
                    eds.push_back(Edge(i, j, x));
                    eds.push_back(Edge(j, i, x));
                }
            }
        }

        d[0]=0;
        for (int i=1; i<n; i++)
            for (Edge &e: eds)
                if (d[e.u] + e.d < d[e.v])
                    d[e.v] = d[e.u] + e.d;

        int mx=0;
        for (int i=1; i<n; i++)
            if (d[i] > mx)
                mx = d[i];

        cout << mx << endl;
    }
}
