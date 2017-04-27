#include <math.h>
#include <stdio.h>
#include <iostream>
#include <list>
#include <bitset>
using namespace std;


#define INF 1073741824


// ------------------------------- FIBONACCI HEAP ------------------------------- //

template<class T>
class FibHeap {
public:
    class FibNode {
        public:
        FibNode(T k, void *pl)
            :key(k),mark(0),p(0),left(0),right(0),child(0),degree(-1),payload(pl) {}

        T key;
        bool mark;
        FibNode *p;
        FibNode *left;
        FibNode *right;
        FibNode *child;
        int degree;
        void *payload;
    };

    FibHeap(): n(0), min(0) {
    }

    ~FibHeap() {
        delete_fibnodes(min);
    }

    void delete_fibnodes(FibNode *x) {
        if (!x) return;

        FibNode *cur = x;
        while(true) {
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
        delete fn;
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

    FibNode* push(T k, void *pl=0) {
        FibNode *x = new FibNode(k, pl);
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

#define MAXN 20001

class Graph {
private:
    struct VD {
        int id, dist;
        VD(int id, int d): id(id), dist(d) {}
        bool operator < (const VD& o) const {
            return dist < o.dist;
        }
    };

    int n;
    list<VD> adj[MAXN];

public:
    Graph(int sz): n(sz) {
        for (int i=0; i<=sz; i++)
            adj[i].clear();
    }

    void connect(int u, int v, int d) {
        adj[u].push_back(VD(v, d));
        adj[v].push_back(VD(u, d));
    }

    int dijkstra (int s, int t) {
        int *dist = new int[n+1];
        FibHeap<VD>::FibNode** pts = new FibHeap<VD>::FibNode*[n+1];
        for (int i=0; i<=n; i++) {
            dist[i] = INF;
            pts[i] = 0;
        }

        FibHeap<VD> Q;
        pts[s] = Q.push(VD(s, dist[s]=0));
        while (!Q.empty()) {
            VD su = Q.top();
            int u = su.id;
            if (u == t) return dist[u];
            Q.pop();

            for (VD uv: adj[u]) {
                int v = uv.id;
                int alt = su.dist + uv.dist;
                if (alt < dist[v]) {
                    VD sv(v, dist[v] = alt);
                    if (pts[v])
                        Q.decreaseKey(pts[v], sv);
                    else
                        pts[v] = Q.push(sv);
                }
            }
        }

        return INF;
    }
};


int main(){
    int T,
        x, y, d,
        n, m, s, t;

    cin>>T;
    for (int cse=1; cse<=T; cse++) {
        cin>>n>>m>>s>>t;
        Graph g(n);

        for (int i=0; i<m; i++) {
            cin>>x>>y>>d;
            g.connect(x, y, d);
        }

        int result = g.dijkstra(s, t);

        printf("Case #%d: ", cse);
        if (result == INF) cout<<"unreachable\n";
        else cout << result << endl;
    }
}
