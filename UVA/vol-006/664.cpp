/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 664
  Name: Single-Player Games
  Problem: https://onlinejudge.org/external/6/664.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
#define EPS 1e-13
using namespace std;


int X[100143], n;
double Mat[33][33], R[33];
vector<int> adj[100143];
void dfs(int id, int j, double m) {
    if (adj[j].empty()) Mat[id][n] += m*X[j];
    else if (j < n) Mat[id][j] -= m;
    else for (int k: adj[j])
        dfs(id, k, m/adj[j].size());
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    cout << fixed << setprecision(3);

    string line;
    for (int cse=1; cin >> n && n; ++cse) {
        cin.ignore(100, '\n');
        for (int i=0; i<n; ++i)
            for (int j=0; j<=n; ++j)
                Mat[i][j] = 0;

        // Read & Parse Input Data
        int id = n;
        for (int i=0; i<n; ++i) {
            getline(cin, line);
            adj[i].clear();
            stack<int> at;
            at.push(i);

            bool eqseen=0;
            bool frst = 1;
            for (int i=0; i<=line.length(); ++i)
                if (line[i] == '(') {
                    if (frst) frst = 0;
                    else adj[id].clear(),
                         at.push(id++);
                }
                else if (line[i] == ')') {
                    int j = at.top();
                    at.pop();
                    if (!at.empty())
                        adj[at.top()].push_back(j);
                }
                else if (line[i]=='-' || isdigit(line[i])) {
                    int r = line[i]=='-' ? 0 : line[i]-'0', j;
                    for (j=i+1; isdigit(line[j]); ++j)
                        r = r*10 + line[j] - '0';
                    if (line[i]=='-')
                        r *= -1;

                    adj[at.top()].push_back(id);
                    adj[id].clear();
                    X[id++] = r;

                    i = j-1;
                }
                else if (line[i] == '=') eqseen = 1;
                else if (eqseen && islower(line[i]))
                    adj[at.top()].push_back(line[i]-'a');
        }

        // Fill System of Linear Equations Matrix
        for (int i=0; i<n; ++i) {
            Mat[i][i] = 1;
            for (int j: adj[i])
                dfs(i, j, 1.0/adj[i].size());
        }

        // Gaussian Forward Elimination
        for (int i=0; i<n; ++i) {
            int im = i;
            for (int k=i+1; k<n; ++k)
                if (fabs(Mat[k][i]) > fabs(Mat[im][i]))
                    im = k;

            if (im != i)
                for (int j=0; j<=n; ++j)
                    swap(Mat[im][j], Mat[i][j]);

            if (fabs(Mat[i][i]) < EPS) continue;

            for (int k=i+1; k<n; ++k) {
                double f = Mat[k][i] / Mat[i][i];

                for (int j=i+1; j<=n; ++j)
                    Mat[k][j] -= f * Mat[i][j];
                Mat[k][i] = 0;
            }
        }

        // Back Substitution
        for (int i=n-1; i>=0; --i) {
            R[i] = Mat[i][n];
            for (int j=i+1; j<n; ++j)
                if (fabs(Mat[i][j]) > EPS)
                    R[i] -= Mat[i][j] * R[j];

            R[i] = fabs(Mat[i][i]) < EPS ? NAN : R[i] / Mat[i][i];
        }

        // Print Result
        cout << "Game " << cse << '\n';
        for (int i=0; i<n; ++i) {
            cout << "Expected score for " << char('a'+i);
            if (isnan(R[i]))
                 cout << " undefined\n";
            else cout << " = " << R[i] << '\n';
        }
        cout << '\n';
    }
}
