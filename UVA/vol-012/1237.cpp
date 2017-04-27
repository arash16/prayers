#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

#define MAXN 10017
char names[MAXN][200];
int L[MAXN], R[MAXN], ord[MAXN];
bool comp(int i, int j) { return L[i]!=L[j] ? L[i]<L[j] : R[i]<R[j]; }
int max(int a, int b, int c) { return a>b && a>c ? a : b > c ? b : c; }

struct Node {
    int ind, maxx;
    Node *left, *right;
    Node(int i, int mx, Node *l, Node *r):ind(i), maxx(mx), left(l),right(r) {}
    ~Node() {
        if (left) delete left;
        if (right) delete right;
    }
};

Node* MakeTree(int lo, int hi) {
    if (lo >= hi) return 0;
    int mid = (lo+hi)>>1;
    Node *l = MakeTree(lo, mid),
         *r = MakeTree(mid+1, hi);
    return new Node(ord[mid], max(R[ord[mid]], l ? l->maxx : 0, r ? r->maxx : 0), l, r);
}


int rind;
int findNode(Node* r, int p) {
    if (!r || r->maxx < p) return 0;

    int ind = r->ind,
        cnt = L[ind] <= p && p <= R[ind] ? 1 : 0;
    if (cnt) rind = ind;

    if (p >= L[ind])
        cnt += findNode(r->right, p);

    if (cnt < 2)
        cnt += findNode(r->left, p);

    return cnt;
}

int main(){
    int T, n, q, p;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i=0; i<n; i++) {
            scanf(" %s %d%d", names[i], L+i, R+i);
            ord[i] = i;
        }
        sort(ord, ord+n, comp);
        Node *root = MakeTree(0, n);

        scanf("%d", &q);
        for (int i=0; i<q; i++) {
            scanf("%d", &p);
            int c = findNode(root, p);
            if (!c || c>1) puts("UNDETERMINED");
            else puts(names[rind]);
        }

        if (T) putchar('\n');
        delete root;
    }
}
