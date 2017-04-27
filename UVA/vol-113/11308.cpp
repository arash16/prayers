#include <stdio.h>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

struct Node {
    int val;
    Node *nxt[26];
    Node(): val(-1) { memset(nxt, 0, sizeof(nxt)); }
    ~Node() {
        for (int i=0; i<26; ++i)
            if (nxt[i])
                delete nxt[i];
    }
};

Node *root;
void setVal(char str[], int val) {
    Node *cur = root;
    for (int i=0; str[i]; ++i) {
        char ch = tolower(str[i])-'a';
        if (!cur->nxt[ch])
            cur->nxt[ch] = new Node();
        cur = cur->nxt[ch];
    }
    cur->val = val;
}

int getVal(char str[]) {
    Node *cur = root;
    for (int i=0; str[i]; ++i)
        cur = cur->nxt[tolower(str[i])-'a'];
    return cur->val;
}




#define MAXL 10000
void skipline() {
    while (getchar()!='\n');
}

typedef pair<int, string> Pair;
int main(){
    int T, n, m, b, c, t;
    scanf("%d", &T);
    char rtitle[MAXL], str[MAXL];
    while (T--) {
        if (root) delete root;
        root = new Node();

        skipline();
        cin.getline(rtitle, MAXL);
        for (int i=0; rtitle[i]; ++i)
            putchar(toupper(rtitle[i]));
        putchar('\n');

        scanf("%d%d%d", &n, &m, &b);

        for (int i=0; i<n; ++i) {
            scanf("%s %d", str, &c);
            setVal(str, c);
        }

        vector<Pair> vec;
        for (int i=0; i<m; ++i) {
            skipline();
            cin.getline(rtitle, MAXL);

            scanf("%d", &t);
            int price = 0;
            for (int j=0; j<t; ++j) {
                scanf("%s %d", str, &c);
                price += c * getVal(str);
            }

            if (price <= b)
                vec.push_back(Pair(price, rtitle));
        }

        if (vec.empty()) puts("Too expensive!");
        else {
            sort(vec.begin(), vec.end());
            for (Pair &p: vec)
                cout << p.second << endl;
        }
        putchar('\n');
    }
}
