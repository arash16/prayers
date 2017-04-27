#include <stdio.h>
#include <cstring>
#include <iostream>
#include <list>
using namespace std;

bool seen[3000];
int today[3000], tomorrow[3000];
list<int> adj[3000];
int main(){
    int T, n, d, u, v;
    scanf("%d", &n);

    for (int i=0; i<n; i++) {
        scanf("%d", &d);
        for (int j=0; j<d; j++) {
            scanf("%d", &v);
            adj[i].push_back(v);
        }
    }

    scanf("%d", &T);
    while (T--) {
        scanf("%d", &u);
        if (!adj[u].size())
            puts("0");
        else {
            memset(seen, 0, n);
            today[0] = u;
            seen[u] = 1;
            int c1 = 1;

            int mx=0, mxi=0, unseen=n;
            for (d=1; c1 && mx<unseen; d++) {
                int c2 = 0;
                for (int i=0; i<c1; i++)
                    for (int v: adj[today[i]])
                        if (!seen[v]) {
                            tomorrow[c2++] = v;
                            seen[v] = 1;
                            unseen--;
                        }

                if (c2 > mx) {
                    mx = c2;
                    mxi = d;
                }
                swap(today, tomorrow);
                c1 = c2;
            }

            printf("%d %d\n", mx, mxi);
        }
    }
}
