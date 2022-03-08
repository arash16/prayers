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

bool treeEq(Tree *t1, Tree *t2) {
  if (t1 == NULL && t2 == NULL) {
    return true;
  }

  if (t1 == NULL || t2 == NULL) {
    return false;
  }

  return treeEq(t1->left, t2->left) && treeEq(t1->right, t2->right);
}

int n, k;
Tree *T[43];
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    while (cin >> n >> k) {
      int count = 0;

      for (int i=0; i<n; ++i) {
        T[i] = NULL;
        for (int j=0; j<k; ++j) {
          int x; cin >> x;
          T[i] = add(T[i], x);
        }

        bool isUnique = true;
        for (int j=0; j<i && isUnique; ++j) {
          if (treeEq(T[i], T[j])) {
            isUnique = false;
          }
        }
        count += isUnique;
      }

      cout << count << endl;
    }
}
