#include <bits/stdc++.h>
using namespace std;


int main() {
    long long n, m;
    for (int cse=1; cin>>n>>m && (n||m); ++cse)
        cout << "Case " << cse << ": " << (n*(n-1)/2*m*(m-1)/2) << endl;
}
