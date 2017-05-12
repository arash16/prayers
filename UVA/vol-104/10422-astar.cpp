#include <bits/stdc++.h>
using namespace std;

string finalS = "111110111100 110000100000";
struct State {
    string ss;
    int d, x, y, h;
    void calcw() {
        int id = ss.find_first_of(' ');
        y = id / 5;
        x = id % 5;
    }
    void calch() {
        int cc=0;
        for (int i=0; i<25; ++i)
            cc += ss[i] != finalS[i];
        h = cc;
    }
    int toInt() {
        int xc=0, xy;
        int result = 0;
        for (int i=0; i<25; ++i) {
            if (ss[i]=='0') ++xc;
            else if (ss[i]==' ') xy=xc;
            result = (result << 1) | (ss[i]=='1');
        }
        return (result<<4)|xy;
    }

    bool operator < (const State &o) const {
        return d + h > o.d + o.h;
    }
};

char S[536870913];
bool isg[] = { 0, 0, 1, 1, 1, 1, 1, 0, 0 };
int dx[] = {  1, -1,  1, -1,  2, -2,  2, -2},
    dy[] = {  2,  2, -2, -2,  1,  1, -1, -1};

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int T;
    cin >> T;
    cin.ignore(100, '\n');
    for (int cse=1; cse<=T; ++cse) {
        State st;
        string str;
        for (int i=0; i<5; ++i) {
            getline(cin, str);
            while (str.length() < 5)
                str += ' ';
            st.ss += str.substr(0, 5);
        }
        st.calcw();
        st.d = 0;

        priority_queue<State> q;
        q.push(st);
        while (!q.empty()) {
            State s = q.top(); q.pop();
            int op = s.y*5 + s.x;
            if (s.ss == finalS) {
                cout << "Solvable in " << s.d << " move(s).\n";
                goto fin;
            }

            if (s.d < 10)
            for (int k=0; k<8; ++k)
                if (isg[s.x+dx[k]+2] && isg[s.y+dy[k]+2]) {
                    State t(s);
                    t.x += dx[k];
                    t.y += dy[k];
                    swap(t.ss[op], t.ss[t.y*5 + t.x]);
                    ++t.d;

                    int id = t.toInt();
                    if (S[id] != cse) {
                        S[id]  = cse;
                        t.calch();
                        q.push(t);
                    }
                }
        }
        cout << "Unsolvable in less than 11 move(s).\n";
        fin:;
    }
}
