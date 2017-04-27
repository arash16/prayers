#include <stdio.h>
#include <iostream>
using namespace std;

int DP[201] = { 0, 1, 3 };
int main() {
    for (int i=3; i<201; i++)
        DP[i] = i + DP[int(i/3) + i%3] - i%3;

    int n;
    while(cin>>n)
        cout << DP[n] <<endl;
}

