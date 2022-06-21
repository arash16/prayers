/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 1610
  Name: Party Games
  Problem: https://onlinejudge.org/external/16/1610.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;

string makep(string r, int i) {
  string s;
  do {
    int m = i % 27;
    i /= 27;
    if (m>0) {
      s = string(1, 'A' + m - 1) + s;
    }
  } while(i>0);
  return r + s;
}

int main() {
  ios_base::sync_with_stdio(0);cin.tie(0);

  int n, i, j;
  string S[1143];
  while (cin >> n && n) {
    for (int i=0; i<n; ++i)
      cin >> S[i];
    sort(S, S+n);

    string s1=S[(n>>1)-1], s2=S[n>>1], r;
    if (s1 == s2) {
      cout << s1 << endl;
      continue;
    }

    for (i=0; s1[i] && s1[i]==s2[i]; ++i)
      r += s1[i];

    if (s1.length() > s2.length() && i==s2.length()-1 && s1[i]==s2[i]-1) {
      while(s1[i+1]=='Z')
        r += s1[i++];
    }

    for (i=0; ;++i) {
      string ss = makep(r, i);
      if (s1<=ss && ss<s2) {
        cout << ss << endl;
        break;
      }
    }
  }
}
