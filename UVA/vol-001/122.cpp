#include <stdio.h>
#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int val;
    Node *left, *right;
    Node(): val(-1), left(0), right(0) {}
    ~Node() {
        if (left) delete left;
        if (right) delete right;
    }
};


int main(){
    char w[10000];
    int x, n;
    for (;;) {
        int free = 1;
        bool dup = 0;
        Node *root = new Node();
        for (n=0; cin>>w && w[1]!=')'; n++) if (!dup) {
            sscanf(w+1, "%d", &x);
            int i=2;
            while (w[i]!=',') i++;

            Node *c = root;
            for (i++; w[i]!=')'; i++) {
                if (w[i] == 'L') {
                    if (!c->left) {
                        c->left = new Node();
                        free++;
                    }
                    c = c->left;
                }
                else {
                    if (!c->right) {
                        c->right = new Node();
                        free++;
                    }
                    c = c->right;
                }
            }

            if (c->val == -1) {
                c->val = x;
                free--;
            }
            else dup=1;
        }
        if (!n) break;

        if (dup || free) puts("not complete");
        else {
            queue<Node*> q;
            q.push(root);
            while (!q.empty()) {
                Node *c = q.front(); q.pop();
                if (c!=root) putchar(' ');
                cout << c->val;

                if (c->left) q.push(c->left);
                if (c->right) q.push(c->right);
            }
            cout << endl;
        }

        delete root;
    }
}
