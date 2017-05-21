#include <bits/stdc++.h>
using namespace std;


char M[10][10];
int click(int i, int j) {
    int cnt = (M[i][j] = !M[i][j]) ? 1 : -1;
    if (i) cnt += (M[i-1][j] = !M[i-1][j]) ? 1 : -1;
    if (j) cnt += (M[i][j-1] = !M[i][j-1]) ? 1 : -1;
    if (i<9) cnt += (M[i+1][j] = !M[i+1][j]) ? 1 : -1;
    if (j<9) cnt += (M[i][j+1] = !M[i][j+1]) ? 1 : -1;
    return cnt;
}

int maxd;
bool IDA(int depth, int ocnt, int i=0, int j=0) {
    if (j == 10) return IDA(depth, ocnt, i+1, 0);
    int h = (ocnt + 4) / 5;
    if (!h) return 1;
    if (depth+h > maxd || i==10) return 0;

    if (!i || !M[i-1][j])
        if (IDA(depth, ocnt, i, j+1)) return 1;

    if (!i || M[i-1][j]) {
        int chng = click(i, j);
        if (IDA(depth + 1, ocnt + chng, i, j+1)) return 1;
        click(i, j);
    }
    return 0;
}


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    string title;
    while (getline(cin, title) && title!="end") {
        int cnt = 0;
        for (int i=0; i<10; ++i) {
            cin >> M[i];
            for (int j=0; j<10; ++j)
                if ((M[i][j] = M[i][j] != '#'))
                    ++cnt;
        }

        for (maxd=0; maxd<101; ++maxd)
            if (IDA(0, cnt)) break;

        cout << title << ' ' << (maxd<=100 ? maxd : -1) << '\n';
        cin.ignore(1000, '\n');
    }
}
