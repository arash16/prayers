#include <math.h>
#include <stdio.h>
#include <iostream>
#include <cstring>
using namespace std;

int main(){
	char line[100];
	int T, n;
	cin>>T;
	cin.getline(line, 100);
	cin.getline(line, 100);

	int mat[30][30], cum[30][30];


	while (T--) {
		for (n=0; cin.getline(line, 100) && line[0]; n++)
			for (int i=0; line[i]; i++) {
				mat[n+1][i+1] = line[i] - '0';
				cum[n+1][i+1] = cum[n][i+1] + mat[n+1][i+1];
			}

		int mx=0;
		for (int i1=0; i1<n; i1++)
			for (int i2=i1+1; i2<=n; i2++) {
				int j1=0;
				int sum=0;
				for (int j2=1; j2<=n; j2++) {
					sum += cum[i2][j2] - cum[i1][j2];
					if ( sum != (i2-i1)*(j2-j1) ) { j1=j2; sum=0; }
					else if (sum > mx) mx = sum;
				}
			}
		cout << mx << endl;


		if (T) cout << endl;
	}
}
