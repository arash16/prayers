#include <stdio.h>
#include <iostream>
#include <list>
using namespace std;

#define MAXN 50001
int nxt[MAXN], prv[MAXN], sze[MAXN], onstack[MAXN];

int main(){
    int cse=1, T, n, u, v;
    cin >> T;
    while (T--) {
        cin>>n;
        for (int i=0; i<n; i++) {
            cin>>u>>v;
            nxt[u-1] = v-1;
            sze[i] = onstack[i] = 0;
        }

        int maxsz=0;
        for (int s=0; s<n; s++)
            if (!sze[s]) {
                int j=s, lj=-1, c=1;
                while (!sze[j] && !onstack[j]) {
                    prv[j] = lj;
                    onstack[j] = c++;
                    j = nxt[lj=j];
                }
                // self circle
                if (!sze[j]) {
                    int sz = c - onstack[j];
                    for (int k=j; !sze[k] && onstack[k]; k=nxt[k]) {
                        onstack[k] = 0;
                        sze[k] = sz;
                    }
                }
                else prv[j]=lj;

                int k, sz = sze[j];
                j = prv[j];
                for (k=j; k!=-1 && onstack[k]; k=prv[k]) {
                    onstack[k] = 0;
                    sze[k] = ++sz;
                }
                maxsz = max(maxsz, sze[s]);
            }

        int maxs=-1;
        for (int i=0; maxs<0 && i<n; i++)
            if (sze[i] == maxsz)
                maxs = i;

        printf("Case %d: %d\n", cse++, maxs+1);
    }
}
