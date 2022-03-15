/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 1588
  Name: Kickdown
  Problem: https://onlinejudge.org/external/15/1588.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;

bool isMatch(string &l1, string &l2, int shift) {
  int l = min(l1.length(), l2.length()-shift);
  for (int i=0; i<l; ++i) {
    if(l1[i]=='2' && l2[i+shift]=='2') {
      return false;
    }
  }
  return true;
}

int bruteforce(string &l1, string &l2) {
  for (int shift = 0; shift < l2.length(); ++shift) {
    if (isMatch(l1, l2, shift)) {
      return max(l1.length() + shift, l2.length());
    }
  }

  return l1.length() + l2.length();
}

int main() {
  ios_base::sync_with_stdio(0);cin.tie(0);

  string l1, l2;
  while (cin >> l1 >> l2) {
    cout << min(bruteforce(l1, l2), bruteforce(l2, l1)) << endl;
  }
}
