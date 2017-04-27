#include <stdio.h>
#include <iostream>
using namespace std;

char mat[110][110];
int DD[127], EE[127], n,m,s,cx,cy,ncx,ncy;
int main(){
	char dirs[] = "NLSO", dir;
	for (int i=0; i<4; i++) {
		DD[dirs[i]] = dirs[(i+1)%4];
		EE[dirs[i]] = dirs[(i+3)%4];
	}

	while (cin>>n>>m>>s && (n||m||s)) {
		while (getchar() != '\n');

		for (int i=0; i<n; i++) {
			for (int j=0; j<m; j++)
				if (DD[mat[i][j] = getchar()]) {
					cx = j;
					cy = i;
					dir = mat[i][j];
					mat[i][j] = '.';
				}
			while (getchar() != '\n');
		}

		int stickers = 0;
		for (int i=0; i<s; i++)
			switch (getchar()) {
				case 'D': dir = DD[dir]; break;
				case 'E': dir = EE[dir]; break;
				case 'F':
					ncx = cx; ncy = cy;
					switch (dir) {
						case 'N': ncy--; break;
						case 'L': ncx++; break;
						case 'S': ncy++; break;
						case 'O': ncx--; break;
					}
					
					if (ncx>=0 && ncx<m && ncy>=0 && ncy<n && mat[ncy][ncx]!='#') {
						cx = ncx;
						cy = ncy;
						
						if (mat[cy][cx] == '*') {
							mat[cy][cx] = '.';
							stickers++;
						}
					}
			}
		
		cout << stickers << endl;
	}
}
