#include <bits/stdc++.h>
using namespace std;


int dx[] = {0, 1, -1,  0},
	dy[] = {1, 0,  0, -1};

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);

	char line[300];
	for (int cse=1; cin.getline(line, 300);) {
		int M[3][3] = {};
		for (int i=0; line[i]; ++i) {
			int k = line[i]-'a',
				u = k/3, v = k % 3;

			M[u][v] = (M[u][v]+1)%10;
			for (int j=0; j<4; ++j) {
				int y = u + dy[j],
					x = v + dx[j];

				if (x>=0 && x<3 && y>=0 && y<3)
					M[y][x] = (M[y][x]+1)%10;
			}
		}

		cout << "Case #" << (cse++) << ":\n";
		for (int i=0; i<3; ++i)
			cout << M[i][0] << ' ' << M[i][1] << ' ' << M[i][2] << endl;
	}
}
