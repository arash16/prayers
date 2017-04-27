#include <math.h>
#include <stdio.h>
#include <cstring>
#include <iostream>
using namespace std;

#define EPS 1e-9
struct Node {
    int val;
    Node *nxt[127];
    Node() {
        val = -1;
        memset(nxt, 0, sizeof(nxt));
    }
    ~Node() {
        for (int i=0; i<127; ++i)
            if (nxt[i])
                delete nxt[i];
    }
};

Node *root;
void assignVal(char str[], int val) {
    Node *cur = root;
    for (int i=0; str[i]; ++i) {
        if (!cur->nxt[str[i]])
            cur->nxt[str[i]] = new Node();

        cur = cur->nxt[str[i]];
    }
    cur->val = val;
}

int readVal(char str[]) {
    Node *cur = root;
    for (int i=0; str[i]; ++i)
        cur = cur->nxt[str[i]];
    return cur->val;
}

bool check(int x, char ch[]) {
    if (ch[0]=='<')
        return ch[1]=='=' ? x<=0 : x<0;

    if (ch[0]=='>')
        return ch[1]=='=' ? x>=0 : x>0;

    return !x;
}

int main() {
    int n, m;
    double x;
    char str[50];
    while (scanf("%d%d", &n, &m)==2) {
        if (root) delete root;
        root = new Node();

        for (int i=0; i<n; ++i) {
            scanf("%s %lf", str, &x);
            assignVal(str, round(x*10));
        }

        for (int i=0; i<m; ++i) {
            int sum = 0;
            char op[3] = "+";
            while (op[0] == '+') {
                scanf("%s %s", str, op);
                sum += readVal(str);
            }

            scanf("%lf", &x);
            sum -= round(x*10);

            printf("Guess #%d was %s.\n", i+1, check(sum, op) ? "correct" : "incorrect");
        }
    }
}
