/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 11572
  Name: Unique Snowflakes
  Problem: https://onlinejudge.org/external/115/11572.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <cstring>
#include <iostream>
using namespace std;

struct Node {
    bool seen;
    Node *nxt[10];
    Node(): seen(0) { memset(nxt, 0, sizeof(nxt)); }
    ~Node() {
        for (int i=0; i<10; ++i)
            if (nxt[i])
                delete nxt[i];
    }
};
Node *root;
bool setval(int ind, bool nval) {
    Node *cur = root;
    for (; ind; ind /= 10) {
        int d = ind % 10;
        if (!cur->nxt[d])
            cur->nxt[d] = new Node();
        cur = cur->nxt[d];
    }
    bool result = cur->seen;
    cur->seen = nval;
    return result;
}


int main(){
    int T, n, X[1000001];
    root = new Node();

    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);

        int mx=0, i;
        for (int j=i=0; j<n; ++j) {
            scanf("%d", X+j);
            if (setval(X[j], true)) {
                for (;i<j && X[i]!=X[j]; ++i)
                    setval(X[i], false);
                ++i;
            }
            mx = max(mx, j-i+1);
        }
        printf("%d\n", mx);

        for (;i < n; ++i)
            setval(X[i], false);
    }
}
