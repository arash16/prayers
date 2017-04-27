#include <stdio.h>
#include <iostream>
using namespace std;

int main() {
    long long int p[51] = { 1, 1};
    for (int i = 2; i < 51; i++)
        p[i] = p[i - 1] + p[i - 2];

    int n;
    while (cin >> n && n)
        cout << p[n] << endl;
}