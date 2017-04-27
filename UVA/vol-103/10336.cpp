#include <stdio.h>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
char mp[1000][1000];
bool seen[1000][1000];

void dfs(int x, int y, char ch) {
    if (seen[x][y] || x<0 || y<0 || x>=n || y>=m || mp[x][y]!=ch) return;
    seen[x][y]=true;
    dfs(x+1, y, ch);
    dfs(x, y+1, ch);
    dfs(x-1, y, ch);
    dfs(x, y-1, ch);
}

struct WD {
    char ch;
    int cnt;

    WD(char ch, int c): ch(ch), cnt(c) {}
    bool operator < (const WD &o) const {
        if (cnt==o.cnt)
            return ch<o.ch;

        return cnt>o.cnt;
    }
};


int cnt[26];
int main(){
    int T;
    cin>>T;
    for (int cse=1; cse<=T; cse++) {
        memset(cnt, 0, sizeof(cnt));

        cin>>n>>m;
        for (int i=0; i<n; i++) {
            cin>>mp[i];
            for (int j=0; j<m; j++)
                seen[i][j]=0;
        }


        for (int i=0; i<n; i++)
            for (int j=0; j<m; j++)
                if (!seen[i][j]) {
                    char ch = mp[i][j];
                    dfs(i, j, ch);
                    cnt[ch-'a']++;
                }

        vector<WD> items;
        for (int i=0; i<26; i++)
            if (cnt[i])
                items.push_back(WD(i+'a', cnt[i]));

        sort(items.begin(), items.end());

        printf("World #%d\n", cse);
        for (const WD& w: items)
            printf("%c: %d\n", w.ch, w.cnt);
    }
}
