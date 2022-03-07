/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 196
  Name: Spreadsheet
  Problem: https://onlinejudge.org/external/1/196.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;

vector<string> vec;
int R[1000][20000], S[1000][20000], cse;
int getCell(int r, int c) {
    if (S[r][c] == cse)
        return R[r][c];

    string &str = vec[R[r][c]];

    int result=0;
    for (int k=0; str[k++]; ) {
        int cc=0, rr=0;
        while (str[k]>='A')
            cc = cc*26 + str[k++]-'A'+1;

        while (str[k] && str[k]!='+')
            rr = rr*10 + str[k++]-'0';

        result += getCell(rr-1, cc-1);
    }

    S[r][c] = cse;
    return R[r][c]=result;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int T, n, m;
    string str;
    cin >> T;
    for (cse=1; cse<=T; ++cse) {
        cin >> m >> n;
        vec.clear();
        for (int i=0; i<n; ++i)
            for (int j=0; j<m; ++j) {
                cin >> str;
                if (str[0] != '=') {
                    int result = 0, sgn = 1, k = 0;
                    if (str[0]=='-') { sgn=-1; ++k; }
                    for (; str[k]; ++k)
                        result = result*10 + str[k]-'0';
                    R[i][j] = result*sgn;
                    S[i][j] = cse;
                }
                else {
                    R[i][j] = vec.size();
                    vec.push_back(str);
                }
            }

        for (int i=0; i<n; ++i) {
            cout << getCell(i, 0);
            for (int j=1; j<m; ++j)
                cout << ' ' << getCell(i, j);
            cout << '\n';
        }
    }
}
