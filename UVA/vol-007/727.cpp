#include <stdio.h>
#include <iostream>
#include <stack>
using namespace std;

int pred[120];
char line[100];

int main(){
    pred['(']=1;
    pred['+']=pred['-']=2;
    pred['*']=pred['/']=3;

    int T;
    cin>>T;

    cin.getline(line, 100);
    cin.getline(line, 100);
    while (T--) {
        stack<char> st;

        while (cin.getline(line, 100) && line[0]) {
            char ch = line[0];
            if (ch>='0' && ch<='9')
                putchar(ch);
            else if (ch == '(')
                st.push(ch);
            else if (ch==')') {
                while ((ch=st.top()) != '(') {
                    putchar(ch);
                    st.pop();
                }
                st.pop();
            }
            else {
                while (!st.empty() && pred[st.top()] >= pred[ch]) {
                    putchar(st.top());
                    st.pop();
                }
                st.push(ch);
            }
        }
        while (!st.empty()) {
            putchar(st.top());
            st.pop();
        }

        if (T) putchar('\n');putchar('\n');
    }
}
