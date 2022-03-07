/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10842
  Name: Traffic Flow
  Problem: https://onlinejudge.org/external/108/10842.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <math.h>
#include <stdio.h>
#include <cstring>
#include <iostream>
#include <list>
using namespace std;


#define INF 1073741824


// ------------------------------- FIBONACCI HEAP ------------------------------- //

template<class T>
class FibHeap {
public:
    class FibNode {
        public:
        T key;
        bool mark;
        int degree;
        FibNode *p;
        FibNode *left;
        FibNode *right;
        FibNode *child;
        FibNode(T k):key(k),mark(0),p(0),left(0),right(0),child(0),degree(-1) {}
    };

    FibHeap(): n(0), min(0) {
    }

    ~FibHeap() {
        delete_fibnodes(min);
    }

    void delete_fibnodes(FibNode *x) {
        if (!x) return;

        FibNode *cur = x;
        while (cur)
            if (cur->left && cur->left != x) {
                FibNode *tmp = cur;
                cur = cur->left;
                if (tmp->child)
                    delete_fibnodes(tmp->child);
                delete tmp;
            }
            else {
                if (cur->child)
                    delete_fibnodes(cur->child);
                delete cur;
                break;
            }
    }

    void insert(FibNode *x) {
        x->degree = 0;
        x->p = 0;
        x->child = 0;
        x->mark = 0;
        if ( min == 0)
            min = x->left = x->right = x;
        else {
            min->left->right = x;
            x->left = min->left;
            min->left = x;
            x->right = min;
            if (x->key < min->key)
                min = x;
        }
        ++n;
    }

    FibNode* minimum() {
        return min;
    }


    static FibHeap* union_fibheap(FibHeap *H1, FibHeap *H2) {
        FibHeap* H = new FibHeap();
        H->min = H1->min;
        if ( H->min != 0 && H2->min != 0 ) {
            H->min->right->left = H2->min->left;
            H2->min->left->right = H->min->right;
            H->min->right = H2->min;
            H2->min->left = H->min;
        }
        if ( H1->min == 0 || ( H2->min != 0 && H2->min->key < H1->min->key ) )
            H->min = H2->min;
        H->n = H1->n + H2->n;
        return H;
    }

    FibNode* extract_min() {
        FibNode *z, *x, *next;
        FibNode ** childList;

        z = min;
        if (z != 0) {
            x = z->child;
            if (x != 0) {
                childList = new FibNode*[z->degree];
                next = x;
                for (int i = 0; i < (int)z->degree; i++) {
                    childList[i] = next;
                    next = next->right;
                }
                for (int i = 0; i < (int)z->degree; i++) {
                    x = childList[i];
                    min->left->right = x;
                    x->left = min->left;
                    min->left = x;
                    x->right = min;
                    x->p = 0;
                }
                delete [] childList;
            }
            z->left->right = z->right;
            z->right->left = z->left;
            if (z == z->right)
                min = 0;
            else {
                min = z->right;
                consolidate();
            }
            n--;
        }
        return z;
    }

    void consolidate() {
        int d, rootSize;
        FibNode *w, *next, *x, *y, *temp,
                **rootList, **A;

        int max_degree = log((double)n)/0.481212 + 3;

        A = new FibNode*[max_degree];
        for (int i=0; i<max_degree; i++)
            A[i]=0;

        w = min;
        rootSize = 0;
        next = w;
        do {
            rootSize++;
            next = next->right;
        } while ( next != w );


        rootList = new FibNode*[rootSize];
        for (int i = 0; i < rootSize; i++) {
            rootList[i] = next;
            next = next->right;
        }

        for (int i = 0; i < rootSize; i++) {
            w = rootList[i];
            x = w;
            d = x->degree;
            while (A[d] != 0) {
                y = A[d];
                if (y->key < x->key) {
                    temp = x;
                    x = y;
                    y = temp;
                }
                fib_heap_link(y,x);
                A[d] = 0;
                d++;
            }
            A[d] = x;
        }
        delete [] rootList;


        min = 0;
        for (int i = 0; i < max_degree; i++)
            if (A[i] != 0) {
                if (min == 0)
                    min = A[i]->left = A[i]->right = A[i];
                else {
                    min->left->right = A[i];
                    A[i]->left = min->left;
                    min->left = A[i];
                    A[i]->right = min;
                    if (A[i]->key < min->key)
                        min = A[i];
                }
            }
        delete [] A;
    }


    void fib_heap_link(FibNode* y, FibNode* x) {
        y->left->right = y->right;
        y->right->left = y->left;
        if (x->child != 0) {
            x->child->left->right = y;
            y->left = x->child->left;
            x->child->left = y;
            y->right = x->child;
        }
        else {
            x->child = y;
            y->right = y;
            y->left = y;
        }
        y->p = x;
        x->degree++;
        y->mark = 0;
    }



    void decreaseKey(FibNode* x, T k) {
        FibNode* y;
        if (x->key < k)
            return;

        x->key = k;
        y = x->p;
        if (y != 0 && x->key < y->key) {
            cut(x,y);
            cascading_cut(y);
        }

        if (x->key < min->key)
        min = x;
    }


    void cut(FibNode* x, FibNode* y) {
        if (x->right == x)
            y->child = 0;
        else {
            x->right->left = x->left;
            x->left->right = x->right;
            if (y->child == x)
                y->child = x->right;
        }
        y->degree--;

        min->right->left = x;
        x->right = min->right;
        min->right = x;
        x->left = min;
        x->p = 0;
        x->mark = 0;
    }


    void cascading_cut(FibNode* y) {
        FibNode* z;
        z = y->p;
        if (z != 0) {
            if (y->mark == 0)
                y->mark = true;
            else {
                cut(y,z);
                cascading_cut(z);
            }
        }
    }

    void remove_fibnode(FibNode* x) {
        decrease_key(x, -INF);
        FibNode *fn = extract_min();
        if (fn) delete fn;
    }


    bool empty() const {
        return n == 0;
    }

    FibNode* topNode() {
        return minimum();
    }

    T top() {
        return minimum()->key;
    }

    void pop() {
        if (empty()) return;

        FibNode *x = extract_min();
        if (x) delete x;
    }

    FibNode* push(T k) {
        FibNode *x = new FibNode(k);
        insert(x);
        return x;
    }

    unsigned int size() {
        return (unsigned int) n;
    }

    int n;
    FibNode *min;
};

// ------------------------------------------------------------------------------ //

struct UD {
    int u, d;
    UD(int u, int d): u(u), d(d) {}
    bool operator < (const UD& o) const { return d > o.d; }
};


#define MAXN 117
bool seen[MAXN];
list<int> adj[MAXN];
short W[MAXN][MAXN], d[MAXN];
FibHeap<UD>::FibNode* pts[MAXN];

int main() {
    int T, n, m, u, v, w;
    scanf("%d", &T);
    for (int cse=1; cse<=T; ++cse) {
        scanf("%d%d", &n, &m);
        for (int i=0; i<n; ++i) {
            memset(W[i], -1, n*sizeof(short));
            adj[i].clear();
            pts[i] = 0;
            d[i] = 0;
        }


        for (int i=0; i<m; ++i) {
            scanf("%d%d%d", &u, &v, &w);
            if (W[u][v] < 0) {
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
            if (w > W[u][v])
                W[u][v] = W[v][u] = w;
        }

        int mn = INF;
        FibHeap<UD> q;
        pts[0] = q.push(UD(0, d[0]=2000));
        for (int i=0; i<n; ++i) {
            UD ud = q.top(); q.pop();
            if (ud.d < mn) mn = ud.d;
            if (i == n-1) break;
            d[u=ud.u] = 2000;

            for (int v: adj[u])
                if (W[u][v] > d[v]) {
                    UD nud(v, d[v] = W[u][v]);
                    if (pts[v])
                         q.decreaseKey(pts[v], nud);
                    else pts[v] = q.push(nud);
                }
        }

        printf("Case #%d: %d\n", cse, mn);
    }
}
