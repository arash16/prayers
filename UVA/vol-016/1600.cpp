#include <bits/stdc++.h>
using namespace std;

struct State {
    int i, j, k, d;
    State(int i, int j, int k, int d):i(i),j(j),k(k),d(d){}
};

int dx[]={1,0,-1,0}, dy[]={0,1,0,-1};
bool B[21][21], seen[21][21][21];
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int T; cin>>T;
    while (T--) {
        int m, n, k; cin>>m>>n>>k;
        for (int i=0; i<m; ++i)
            for (int j=0; j<n; ++j) {
                memset(seen[i][j], 0, k+1);
                cin >> B[i][j];
            }


        int result = -1;
        queue<State> q;
        q.push(State(0, 0, 0, 0));
        while (!q.empty()) {
            State s = q.front(); q.pop();
            if (s.i == m-1 && s.j == n-1) {
                result = s.d;
                break;
            }

            for (int i=0; i<4; ++i) {
                int ny=s.i+dy[i], nx=s.j+dx[i];
                if (ny>=0 && ny<m && nx>=0 && nx<n) {
                    int nk = B[ny][nx] ? s.k+1 : 0;
                    if (nk <= k && !seen[ny][nx][nk]) {
                        q.push(State(ny, nx, B[ny][nx]?s.k+1:0, s.d+1));
                        seen[ny][nx][nk] = 1;
                    }
                }
            }
        }

        cout << result << endl;
    }
}
