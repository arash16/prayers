#include <bits/stdc++.h>
using namespace std;


int primes[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29 };
void multFactor(int R[], int x, int sgn) {
    for (int i=x; i>1; --i) {
        int p = i;
        for (int j=0; primes[j] <= p; ++j)
            while (p % primes[j] == 0) {
                p /= primes[j];
                R[j] += sgn;
            }
    }
}

int calc(int C[]) {
    int R[10] = {}, sum = 0;
    for (char ch='a'; ch<='z'; ++ch)
        if (C[ch]) {
            sum += C[ch];
            multFactor(R, C[ch], -1);
        }
    multFactor(R, sum, 1);

    int result = 1;
    for (int i=0; i<10; ++i)
        result *= pow(primes[i], R[i]);
    return result;
}



int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    string str;
    while (cin >> str && str != "#") {
        int C[128] = {};
        for (char ch: str)
            C[ch]++;

        int sum = 1;
        for (int i=0; str[i]; ++i) {
            for (char ch='a'; ch<str[i]; ++ch)
                if (C[ch] > 0) {
                    C[ch]--;
                    sum += calc(C);
                    C[ch]++;
                }
            C[str[i]]--;
        }

        cout << setw(10) << sum << endl;
    }
}
