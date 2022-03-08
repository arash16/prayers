/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 1738
  Name: Ceiling Function
  Problem: https://onlinejudge.org/external/17/1738.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;

struct Tree {
  int value;
  Tree *left;
  Tree *right;
};

Tree *add(Tree *t, int x) {
  if (t == NULL) {
    t = new Tree();
    t->value = x;
    return t;
  }

  if (t->value > x) {
    t->left = add(t->left, x);
  } else {
    t->right = add(t->right, x);
  }
  return t;
}

void treeType(Tree *t, int &b, int &x) {
  ++x;
  if (t == NULL) {
    b |= 1 << x;
    return;
  }

  treeType(t->left, b, x);
  treeType(t->right, b, x);
}

int n, k;
Tree *T[43];
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    while (cin >> n >> k) {
      set<int> types;

      for (int i=0; i<n; ++i) {
        Tree *T = NULL;
        for (int j=0; j<k; ++j) {
          int x; cin >> x;
          T = add(T, x);
        }

        int b = 0, x = -1;
        treeType(T, b, x);
        types.insert(b);
      }

      cout << types.size() << endl;
    }
}
