/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 467
  Name: Synching Signals
  Problem: https://onlinejudge.org/external/4/467.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
#define INF 67108864
using namespace std;

template<class T>
class IndexQueue {
    int mind, maxd;
    vector<T> V[4000];
    void _update() {
        while (mind<=maxd && V[mind].empty()) ++mind;
        if (mind>maxd) clear();
    }

    public:
    IndexQueue() { mind=INF; maxd=-1; }
    bool empty() { _update(); return mind>maxd; }
    void clear() {
        for (int i=mind; i<=maxd; ++i)
            V[i].clear();
        mind=INF;
        maxd=-1;
    }

    void push(int key, T data) {
        V[key].push_back(data);
        if (key < mind) mind = key;
        if (key > maxd) maxd = key;
    }

    int top() { return mind; }
    T pop() {
        _update();
        T r = V[mind].back();
        V[mind].pop_back();
        return r;
    }
};

// ----------------------------------------------------------------

inline bool isdigit(char ch) { return ch>='0' && ch<='9'; }

IndexQueue<int> q;
int X[10043], n;
bool isg[17];
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    string line;
    for (int cse=1; getline(cin, line); ++cse) {
        int x = n = 0;
        for (int i=0; i<line.length(); ++i)
            if (isdigit(line[i]))
                x = x*10 + line[i]-'0';
            else {
                X[n++] = x;
                x = 0;
            }
        if (isdigit(line[line.length()-1]))
            X[n++] = x;

        if (!n) continue;
        cout << "Set " << cse;

        q.clear();
        for (int i=0; i<n; ++i) {
            q.push(X[i]-5, i);
            isg[i] = 1;
        }

        int gcn = n;
        while (!q.empty()) {
            int tm = q.top(),
                id = q.pop();

            if ((gcn += isg[id] ? -1 : 1) == n && (q.empty() || q.top()!=tm)) {
                cout << " synchs again at " << (tm/60) << " minute(s) and " << (tm%60) << " second(s) after all turning green.\n";
                goto fin;
            }

            isg[id] = !isg[id];
            int ntm = tm + X[id] + (isg[id] ? -5 : 5);
            if (ntm <= 3600)
                q.push(ntm, id);
        }
        cout << " is unable to synch after one hour.\n";
        fin:;
    }
}
