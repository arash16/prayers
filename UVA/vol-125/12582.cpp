#include <stdio.h>
#include <cstring>
#include <iostream>
#include <stack>
using namespace std;

int main(){
    char ch, line[100];
    int T, cnt[26];
    cin>>T;
    for (int cse=1; cse<=T; cse++) {
        cin>>line;

        memset(cnt, 0, sizeof(cnt));
        stack<char> st;

        cnt[line[0]-'A']=-1;
        st.push(line[0]);
        for (int i=1; (ch=line[i]); i++) {
            cnt[st.top()-'A']++;
            if (st.top() == ch)
                 st.pop();
            else st.push(ch);
        }

        printf("Case %d\n", cse);
        for (int i=0; i<26; i++)
            if (cnt[i])
                printf("%c = %d\n", 'A'+i, cnt[i]);
    }
}
