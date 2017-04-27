#include <bits/stdc++.h>
#define INF 1073741824
using namespace std;

inline int readchar() {
    const int N = 4194304;
    static char buf[N];
    static char *p = buf, *end = buf;
    bool fin = 0;
    if (fin) return EOF;
    if (p == end) {
        if ((end = buf + fread(buf, 1, N, stdin)) == buf) {
        	fin = 1;
        	return EOF;
    	}
        p = buf;
    }
    return *p++;
}

inline bool isdigit(char ch) { return ch>='0' && ch<='9'; }
inline int readUInt() {
	char ch;
	unsigned int r=0;
	while (!isdigit(ch=readchar()))
		if (ch == EOF) return EOF;
	r = ch-'0';
	while (isdigit(ch=readchar()))
		r = (r<<3) + (r<<1) + ch-'0';

	while (ch!=' ' && ch!='\n')
		ch = readchar();
	return r;
}

// ----------------------------------------------------------------

template<class T, class lesss=less<T> >
class FiboHeap {
lesss comp;
public:
	class Node {
		public:
		T key;
		bool mark;
		int degree;
		Node *p;
		Node *left;
		Node *right;
		Node *child;
		Node(T k):key(k),mark(0),p(0),left(0),right(0),child(0),degree(-1) {}
	};

	FiboHeap(): n(0), min(0) { }

	~FiboHeap() {
		delete_Nodes(min);
	}

	void delete_Nodes(Node *x) {
		if (!x) return;

		Node *cur = x;
		while (cur)
			if (cur->left && cur->left != x) {
				Node *tmp = cur;
				cur = cur->left;
				if (tmp->child)
					delete_Nodes(tmp->child);
				delete tmp;
			}
			else {
				if (cur->child)
					delete_Nodes(cur->child);
				delete cur;
				break;
			}
	}

	void insert(Node *x) {
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
			if (comp(x->key, min->key))
				min = x;
		}
		++n;
	}

	Node* minimum() {
		return min;
	}

	Node* extract_min() {
		Node *z, *x, *next;
		Node ** childList;

		z = min;
		if (z != 0) {
			x = z->child;
			if (x != 0) {
				childList = new Node*[z->degree];
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
		Node *w, *next, *x, *y, *temp,
				**rootList, **A;

		int max_degree = log((double)n)/0.481212 + 3;

		A = new Node*[max_degree];
		for (int i=0; i<max_degree; i++)
			A[i]=0;
		
		w = min;
		rootSize = 0;
		next = w;
		do {
			rootSize++;
			next = next->right;
		} while ( next != w );
		
		
		rootList = new Node*[rootSize];
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
				if (comp(y->key, x->key)) {
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
					if (comp(A[i]->key, min->key))
						min = A[i];
				}
			}
		delete [] A;
	}


	void fib_heap_link(Node* y, Node* x) {
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


	void decreaseKey(Node* x, T k) {
		Node* y;
		if (comp(x->key, k))
			return;

		x->key = k;
		y = x->p;
		if (y != 0 && comp(x->key, y->key)) {
			cut(x,y);
			cascading_cut(y);
		}

		if (comp(x->key, min->key))
		min = x;
	}


	void cut(Node* x, Node* y) {
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


	void cascading_cut(Node* y) {
		Node* z;
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

	void remove_Node(Node* x) {
		decrease_key(x, -INF);
		Node *fn = extract_min();
		if (fn) delete fn;
	}
  

	bool empty() const {
		return n == 0;
	}

	Node* topNode() {
		return minimum();
	}

	T top() {
		return minimum()->key;
	}

	void pop() {
		if (empty()) return;

		Node *x = extract_min();
		if (x) delete x;
	}

	Node* push(T k) {
		Node *x = new Node(k);
		insert(x);
		return x;
	}

	unsigned int size() {
		return (unsigned int) n;
	}

	int n;
	Node *min;
};

// ---------------------------------------------------------------------------------

#define MAXN 1017

int X[MAXN][MAXN],
	D[MAXN][MAXN], n, m,
	dy[] = {0,0,1,-1},
	dx[] = {1,-1,0,0};

struct State {
	int i, j;
	State():i(0),j(0){}
	State(int i, int j):i(i),j(j){}
	bool operator < (const State &s) const { return D[i][j] < D[s.i][s.j]; }
	bool isvalid() { return i>=0 && i<n && j>=0 && j<m; }
};


int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	FiboHeap<State>::Node* N[MAXN][MAXN];

	int T = readUInt();
	while (T--) {
		n = readUInt();
		m = readUInt();
		
		for (int i=0; i<n; ++i)
			for (int j=0; j<m; ++j) {
				X[i][j] = readUInt();
				N[i][j] = NULL;
				D[i][j] = INF;
			}
		
		FiboHeap<State> q;
		N[0][0] = q.push(State(0,0));
		D[0][0] = X[0][0];

		while (!q.empty()) {
			State s = q.top(); q.pop();
			int dd = D[s.i][s.j];
			if (s.i==n-1 && s.j==m-1) {
				cout << dd << endl;
				break;
			}

			for (int k=0; k<4; ++k) {
				State t(s.i+dy[k], s.j+dx[k]);
				if (t.isvalid()) {
					int nd = X[t.i][t.j] + dd;
					if (nd < D[t.i][t.j]) {
						D[t.i][t.j] = nd;
						if (N[t.i][t.j])
							q.decreaseKey(N[t.i][t.j], t);
						else
							N[t.i][t.j] = q.push(t);
					}
				}
			}
		}
	}
}
