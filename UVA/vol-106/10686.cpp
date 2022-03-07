/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10686
  Name: SQF Problems
  Problem: https://onlinejudge.org/external/106/10686.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


char toid(char ch) { return ch<='Z' ? ch-'A' : ch-'a'+26; }

struct Trie {
    int *vals, vc;
    Trie *nxt[52];
    Trie():vals(0), vc(0) { memset(nxt, 0, sizeof(nxt)); }
    ~Trie() {
        if (vals) delete [] vals;
        for (int i=0; i<52; ++i)
            if (nxt[i])
                delete nxt[i];
    }
};

Trie *root;
void setVal(char str[], int val) {
    Trie *cur = root;
    for (int i=0; str[i]; ++i) {
        char ch = toid(str[i]);
        if (!cur->nxt[ch])
            cur->nxt[ch] = new Trie();
        cur = cur->nxt[ch];
    }
    if (!cur->vals) cur->vals = new int[31];
    cur->vals[cur->vc++] = val;
}

Trie* getVal(char str[]) {
    Trie *cur = root;
    for (int i=0; str[i]; ++i) {
        char ch = toid(str[i]);
        cur = cur->nxt[ch];
        if (!cur) return NULL;
    }
    return cur->vc ? cur : NULL;
}

// -----------------------------------------------------------------------------------------

bool seen[31];
char cat[31][1000], str[150];
int main(){
    int T, n, m, cap[31], catc[31];
    scanf("%d", &T);
    while (T--) {
        if (root) delete root;
        root = new Trie();

        scanf("%d", &n);
        vector<int> cats;
        for (int i=0; i<n; ++i) {
            catc[i] = 0;
            scanf("%s%d%d", cat[i], &m, cap+i);
            if (!cap[i]) cats.push_back(i);
            for (int j=0; j<m; ++j) {
                scanf("%s", str);
                setVal(str, i);
            }
        }

        while (getchar()!='\n');
        while (cin.getline(str, 150) && str[0]) {
            char *p = str, l;
            while (true) {
                for (l=0; isalpha(p[l]); ++l);
                if (l) {
                    p[l] = 0;
                    Trie* catids = getVal(p);
                    if (catids) {
                        memset(seen, 0, n);
                        int j = 0;
                        for (int i=0; i < catids->vc; ++i) {
                            int catid = catids->vals[i];
                            if (seen[catid])
                                catids->vals[j++] = catid;
                            else {
                                seen[catid] = true;
                                if (++catc[catid] == cap[catid])
                                    cats.push_back(catid);
                            }
                        }
                        catids->vc = j;
                    }
                }
                else if (!p[0]) break;
                p += l + 1;
                while (*p && !isalpha(*p)) p++;
            }
        }

        if (cats.empty()) puts("SQF Problem.");
        else {
            sort(cats.begin(), cats.end());
            printf("%s", cat[cats[0]]);
            for (int i=1; i<cats.size(); ++i)
                printf(",%s", cat[cats[i]]);
            putchar('\n');
        }
    }
}
