#include <bits/stdc++.h>
using namespace std;


char ord[20];
void dfs(int depth, int n) {
    string indent(2*depth, ' ');

    if (depth == n) {
        cout << indent << "writeln(" << ord[0];
        for (int i=1; i<n; ++i)
            cout << ',' << ord[i];
        cout << ")\n";
        return;
    }

    ord[depth] = char('a' + depth);
    for (int i=depth; i>=0; --i) {
        cout << indent;
        if (i < depth) {
            cout << "else";
            if (i > 0) cout << ' ';
        }
        if (i > 0) cout << "if " << ord[i-1] << " < " << char('a'+depth) << " then\n";
        else cout << '\n';
        dfs(depth + 1, n);
        swap(ord[i-1], ord[i]);
    }

    for (int i=0; i<depth; ++i)
        swap(ord[i], ord[i+1]);
}

char BUF[1000000];
int main() {
    cout.rdbuf()->pubsetbuf(BUF, 1000000);
    ios_base::sync_with_stdio(0);cin.tie(0);

    int T, n;
    cin >> T;
    while (T--) {
        cin >> n;

        cout << "program sort(input,output);\nvar\na";
        for (int i=1; i<n; ++i)
            cout << ',' << char('a'+i);
        cout << " : integer;\nbegin\n  readln(a";
        for (int i=1; i<n; ++i)
            cout << ',' << char('a'+i);
        cout << ");\n";

        ord[0] = 'a';
        dfs(1, n);
        cout << "end.\n";
        if (T) cout << '\n';
    }
}
