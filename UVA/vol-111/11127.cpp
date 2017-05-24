#include <bits/stdc++.h>
using namespace std;


int n;
char str[43];
bool check(int pos, int len) {
    for (int i=0; i<len; ++i) {
        char ch = str[pos+i];
        if (ch!=str[len+pos+i] || ch!=str[len+len+pos+i])
            return 0;
    }
    return 1;
}

//unordered_map<string, int> memo;
int backtrack(int pos) {
    for (int len=pos/3; len>0; --len)
        if (check(pos-3*len, len))
            return 0;

    if (pos == n) return 1;
    if (str[pos] != '*')
        return backtrack(pos+1);

    //auto rr = memo.emplace(str, 0);
    //if (!rr.second) return rr.first->second;

    str[pos] = '0';
    int sum = backtrack(pos+1);
    str[pos] = '1';
    sum += backtrack(pos+1);
    str[pos] = '*';
    //rr.first->second = sum;
    return sum;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    for (int cse=1; cin >> n >> str; ++cse)
        cout << "Case " << cse << ": " << backtrack(0) << '\n';
}
