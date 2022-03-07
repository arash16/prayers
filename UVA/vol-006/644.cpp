/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 644
  Name: Immediate Decodability
  Problem: https://onlinejudge.org/external/6/644.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
using namespace std;

struct Node {
    bool val;
    Node *l, *r;

    Node():val(0),l(0),r(0){}
    ~Node() {
        if (l) delete l;
        if (r) delete r;
    }
};

int main(){
    char w[1000];
    for (int cse=1; ; cse++) {
        bool f = true, some=0;
        Node *root = new Node();
        while (cin>>w && w[0]!='9') {
            some = true;
            if (f) {
                bool np = false;
                Node *c=root;
                for (int i=0; f && w[i]; i++) {
                    if (w[i]=='0') {
                        if (!c->l) {
                            c->l = new Node();
                            np = true;
                        }
                        c = c->l;
                    }
                    else {
                        if (!c->r) {
                            c->r = new Node();
                            np = true;
                        }
                        c = c->r;
                    }
                    if (c->val) f = false;
                }
                c->val = true;
                if (!np) f = false;
            }
        }
        if (!some) break;
        printf("Set %d is %simmediately decodable\n", cse, f?"":"not ");
        delete root;
    }
}
