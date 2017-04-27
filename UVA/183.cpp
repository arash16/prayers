#include <stdio.h>
#include <iostream>
using namespace std;

int n, m;
char tp, line[100000], buf[110], X[300][300];
int enc(char *res, int r1, int c1, int r2, int c2) {
	if (r1==r2 || c1==c2) return 0;
	if (r2-r1==1 && c2-c1==1) {
		res[0] = X[r1][c1];
		return 1;
	}

	int mr = (r1+r2+1)>>1,
		mc = (c1+c2+1)>>1,
		s = 1;

	res[0] = 'D';
	s += enc(res+s, r1, c1, mr, mc);
	s += enc(res+s, r1, mc, mr, c2);
	s += enc(res+s, mr, c1, r2, mc);
	s += enc(res+s, mr, mc, r2, c2);

	if (s<=5) {
		for (int i=2; i<s; i++)
			if (res[1] != res[i])
				return s;
		res[0] = res[1];
		return 1;
	}
	return s;
}

int dec(int ind, int r1, int c1, int r2, int c2) {
	if (r1==r2 || c1==c2) return 0;
	if (line[ind] != 'D') {
		char ch = line[ind]=='0'?'0':'1';
		for (int i=r1; i<r2; i++)
			for (int j=c1; j<c2; j++)
				X[i][j] = ch;
		return 1;
	}

	int mr = (r1+r2+1)>>1,
		mc = (c1+c2+1)>>1;

	int s = 1;
	s += dec(ind + s, r1, c1, mr, mc);
	s += dec(ind + s, r1, mc, mr, c2);
	s += dec(ind + s, mr, c1, r2, mc);
	s += dec(ind + s, mr, mc, r2, c2);
	return s;
}


int main() {
	cin.getline(buf, 100);
	while (buf[0]!='#' && sscanf(buf, "%c%d%d", &tp, &n, &m)==3) {
		if (tp == 'B') {
			int k=0;
			while (cin.getline(buf, 100)) {
				if (buf[1]==' ' && (buf[0]=='B' || buf[0]=='D')) break;
				for (int i=0; buf[i]; i++)
					line[k++] = buf[i];
			}
			line[k] = 0;


			for (int i=0; i<n; i++)
				for (int j=0; j<m; j++)
					X[i][j] = line[i*m + j];

			line[enc(line, 0, 0, n, m)]=0;
			printf("D%4d%4d\n", n, m);
			for (int i=0; line[i]; i++) {
				if (i && i%50==0)
					putchar('\n');
				putchar(line[i]);
			}
			putchar('\n');
		}
		else {
			cin.getline(line, 100000);
			cin.getline(buf, 100);
			dec(0, 0, 0, n, m);
			printf("B%4d%4d\n", n, m);

			int cnt = 0;
			for (int i=0; i<n; i++)
				for (int j=0; j<m; j++) {
					putchar(X[i][j]);
					if (++cnt == 50) {
						putchar('\n');
						cnt = 0;
					}
				}
			if (cnt) putchar('\n');
		}
	}
}
