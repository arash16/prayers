#include <stdio.h>
#include <cstring>
#include <iostream>
using namespace std;


int main() {
    int n;
    char str[110];
    while (cin >> n && n) {
        cin >> str;
        int l = strlen(str);
        int gl = l / n;
        for (int i = 0; i < n; i++) {
            char *gs = str + i*gl;
            for (int j = (gl-1) >> 1; j >= 0; j--) {
                char t = gs[j];
                gs[j] = gs[gl - j - 1];
                gs[gl - j - 1] = t;
            }
        }
        cout << str << endl;
    }
}