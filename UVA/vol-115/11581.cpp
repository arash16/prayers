#include <bits/stdc++.h>
using namespace std;

int f(int g) {
	return 
		( (g>>1) & 0x0DB ) ^
		( (g<<1) & 0x1B6 ) ^
		( (g>>3) & 0x03F ) ^
		( (g<<3) & 0x1F8 );
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);

	int T, seen[512];
	cin >> T;
	while (T--) {
		int g = 0;
		for (int i=0; i<9; ++i) {
			char ch;
			cin >> ch;
			g <<= 1;
			if (ch == '1')
				g |= 1;
		}
		
		memset(seen, -1, sizeof(seen));

		int fi = g, i;
		for (i=0; seen[fi]<0; ++i) {
			seen[fi] = i;
			fi = f(fi);
		}
		cout << seen[fi]-1 << endl;
	}
}
