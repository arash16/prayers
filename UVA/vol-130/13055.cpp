#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);cin.tie(0);

  int n;
  while (cin >> n) {
    stack<string> D;
    for (int i=0; i<n; ++i) {
      string cm, name;
      cin >> cm;
      switch(cm[0]) {
        case 'S':
          cin >> name;
          D.push(name);
          break;

        case 'K':
          if (!D.empty())
            D.pop();
          break;

        case 'T':
          cout << (D.empty() ? "Not in a dream" : D.top()) << endl;
          break;
      }
    }
  }
}
