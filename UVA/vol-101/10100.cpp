#include <bits/stdc++.h>
using namespace std;


void tokenize(const string& s, vector<string> &v) {
    char ss[1043];
    for (int i=0, j; s[i]; ++i)
        if (isalnum(s[i])) {
            for (j=i; isalnum(s[j]); ++j)
                ss[j-i] = s[j];
            ss[j-i] = 0;
            v.push_back(ss);
            i = j-1;
        }
}

int DP[1043][1043];
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    string l1, l2;
    for (int cse=1; getline(cin, l1) && getline(cin, l2); ++cse) {
        vector<string> v1, v2;
        tokenize(l1, v1);
        tokenize(l2, v2);

        cout << setw(2) << cse;
        if (v1.empty() || v2.empty())
            cout << ". Blank!\n";
        else {
            for (int i=1; i<=v1.size(); ++i)
                for (int j=1; j<=v2.size(); ++j)
                    if (v1[i-1]==v2[j-1])
                        DP[i][j] = DP[i-1][j-1] + 1;
                    else
                        DP[i][j] = max(DP[i-1][j], DP[i][j-1]);
            cout << ". Length of longest match: " << DP[v1.size()][v2.size()] << endl;
        }
    }
}
