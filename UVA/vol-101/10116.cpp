#include <stdio.h>
#include <iostream>
using namespace std;


int main(){
	int r, c, x, s[20][20];
	char g[20][20];
	while (cin>>r>>c>>x && (r || c || x)) {
		for (int i=0; i<r; i++) {
			cin>>g[i];
			for (int j=0; j<c; j++)
				s[i][j]=0;
		}

		int cx=x-1, cy=0, cp=0;
		for (;cx>=0 && cx<c && cy>=0 && cy<r && !s[cy][cx];) {
			s[cy][cx] = ++cp;
			switch (g[cy][cx]) {
				case 'N': cy--; break;
				case 'S': cy++; break;
				case 'W': cx--; break;
				case 'E': cx++; break;
			}
		}
		
		if (cx<0 || cx>=c || cy<0 || cy>=r)
			 printf("%d step(s) to exit\n", cp);
		else printf("%d step(s) before a loop of %d step(s)\n", s[cy][cx]-1, cp-s[cy][cx]+1);
	}
}
