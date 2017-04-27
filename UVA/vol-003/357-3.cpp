#include <bits/stdc++.h>
using namespace std;

int C[] = {1,5,10,25,50}, n;
long long DP[30143];
int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);

	DP[0] = 1;
	for (int i=0; i<5; ++i)
		for (int j=0; j<30000; ++j)
			DP[j+C[i]] += DP[j];

	while (cin >> n)
		if (DP[n] == 1)
			cout << "There is only 1 way to produce " << n << " cents change.\n";
		else
			cout << "There are " << DP[n] << " ways to produce " << n << " cents change.\n";
}
