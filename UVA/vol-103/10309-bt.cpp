#include <bits/stdc++.h>
using namespace std;


bool M[10][10];
int click(int i, int j) {
    int cnt = (M[i][j] = !M[i][j]) ? 1 : -1;
    if (i) cnt += (M[i-1][j] = !M[i-1][j]) ? 1 : -1;
    if (j) cnt += (M[i][j-1] = !M[i][j-1]) ? 1 : -1;
    if (i<9) cnt += (M[i+1][j] = !M[i+1][j]) ? 1 : -1;
    if (j<9) cnt += (M[i][j+1] = !M[i][j+1]) ? 1 : -1;
    return cnt;
}

int best;
void backtrack(int step, int ocnt, int i=0, int j=0) {
    if (j == 10) ++i, j=0;

    int h = (ocnt + 4) / 5;
    if (!h) best = min(best, step);
    if (step+h >= best || i==10) return;

    if (!i || !M[i-1][j])
        backtrack(step, ocnt, i, j+1);

    if (step+h >= best) return;
    if (!i || M[i-1][j]) {
        int chng = click(i, j);
        backtrack(step + 1, ocnt + chng, i, j+1);
        click(i, j);
    }
}


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    string title, ln;
    while (getline(cin, title) && title!="end") {
        int cnt = 0;
        for (int i=0; i<10; ++i) {
            cin >> ln;
            for (int j=0; j<10; ++j)
                if ((M[i][j] = ln[j] != '#'))
                    ++cnt;
        }

        best = 101;
        backtrack(0, cnt);

        cout << title << ' ' << (best<=100 ? best : -1) << '\n';
        cin.ignore(1000, '\n');
    }
}
