/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 592
  Name: Island of Logic
  Problem: https://onlinejudge.org/external/5/592.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;

#define DIVINE 0
#define HUMAN 1
#define EVIL 2
#define LYING 3
#define DAY 1
#define NIGHT 0

string types[] = {
  "divine",
  "human",
  "evil",
};

inline bool ends_with(string const &value, string const &postfix) {
  if (postfix.size() > value.size()) return false;
  return equal(postfix.rbegin(), postfix.rend(), value.rbegin());
}

struct fact {
  int src;
  int dest;
  bool nott;
  bool isDay;
  bool isLying;
  bool isSome;
  int isWhat;
};

vector<int> trans(int x) {
  x >>= 1;
  vector<int> guys;
  for (int i=0; i<5; ++i) {
    guys.push_back(x % 3);
    x /= 3;
  }
  return guys;
}

bool isFeasible(vector<fact> facts, bool isDay, vector<int> guys) {
  for (fact f: facts) {
    bool saysTruth;
    if (f.isDay) {
      saysTruth = (isDay && !f.nott) || (!isDay && f.nott);
    }

    if (f.isSome) {
      saysTruth = (!f.nott && guys[f.dest] == f.isWhat) || (f.nott && guys[f.dest] != f.isWhat);
    }

    if (f.isLying) {
      bool destIsLyar = (!isDay && guys[f.dest] == HUMAN) || guys[f.dest] == EVIL;
      saysTruth = (!f.nott && destIsLyar) || (f.nott && !destIsLyar);
    }

    bool srcIsLyar = (!isDay && guys[f.src] == HUMAN) || guys[f.src] == EVIL;
    if ((srcIsLyar && saysTruth) || (!srcIsLyar && !saysTruth)) {
      return false;
    }
  }

  return true;
}

int main() {
  ios_base::sync_with_stdio(0);cin.tie(0);

  int n, cse=1;
  while (cin >> n && n) {
    string ln;
    getline(cin, ln);
    vector<fact> facts;
    for (int i=0; i<n; ++i) {
      getline(cin, ln);
      
      fact f;
      f.isDay = f.isSome = f.isWhat = f.isLying = false;
      f.dest = 0;
      f.src = ln[0] - 'A';
      f.nott = ln[9] == 'o';
      
      if (ends_with(ln, "day.")) {
        f.isDay = true;
        f.nott = false;
      }
      else if (ends_with(ln, "night.")) {
        f.isDay = true;
        f.nott = true;
      }
      else {
        f.dest = ln[3] == 'I' ? f.src : (ln[3] - 'A');
        if (ends_with(ln, "divine.")) {
          f.isSome = true;
          f.isWhat = DIVINE;
        } else if (ends_with(ln, "human.")) {
          f.isSome = true;
          f.isWhat = HUMAN;
        } else if (ends_with(ln, "evil.")) {
          f.isSome = true;
          f.isWhat = EVIL;
        } else if (ends_with(ln, "lying.")) {
          f.isLying = true;
        }
      }

      facts.push_back(f);
    }
    
    // ---------------------------------------------
    bool isPossible = false;
    int day = -1, fguys[5];
    memset(fguys, -1, sizeof(fguys));

    for (int i=0; i<3*3*3*3*3*2; ++i) {
      bool isDay = i&1;
      vector<int> guys = trans(i);

      if (isFeasible(facts, isDay, guys)) {
        isPossible = true;

        if (day == -1) day = isDay;
        else if (day != isDay) day = -2;

        for (int i=0; i<5; ++i) {
          if (fguys[i] == -1) fguys[i] = guys[i];
          else if (fguys[i] != guys[i]) fguys[i] = -2;
        }
      }
    }

    cout << "Conversation #" << (cse++) << endl;
    if (!isPossible) {
      cout << "This is impossible." << endl;
    } else {
      bool someDeduced = day >= 0;
      for (int i=0; i<5; ++i) {
        if (fguys[i]>=0) {
          cout << char('A' + i) << " is " << types[fguys[i]] << "." << endl;
          someDeduced = true;
        }
      }
      if (day == 0) cout << "It is night." << endl;
      else if (day == 1) cout << "It is day." << endl;
      if (!someDeduced) {
        cout << "No facts are deducible." << endl;
      }
    }
    cout << endl;
  }
}
