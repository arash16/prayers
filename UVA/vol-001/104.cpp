#include <math.h>
#include <stdio.h>
#include <cstring>
#include <iostream>
using namespace std;

#define INF 1e100
double d[22][22], M[22][22];
int p[22][22], path[22];

int main(){
	int n;
	double x;
	while (cin>>n) {
		for (int i=0; i<n; i++)
			for (int j=0; j<n; j++) {
				if (i==j) M[i][i] = 0;
				else {
					cin>>x;
					M[i][j] = -log(x);
				}
			}

		int mn = n;
		for (int s=0; s<n; s++) {
			for (int i=0; i<n; i++) {
				d[0][i] = M[s][i];
				p[0][i] = s;
			}

			for (int i=1; i<mn; i++) {
				for (int j=0; j<n; j++)
					d[i][j] = INF;

				for (int u=0; u<n; u++)
					for (int v=0; v<n; v++)
						if (d[i-1][u] + M[u][v] < d[i][v]) {
							d[i][v] = d[i-1][u] + M[u][v];
							p[i][v] = u;
						}

				if (d[i][s]<0 && exp(-d[i][s])>1.01) {
					mn = i;
					int u = s;
					for (int j=i; j>=0; j--) {
						path[j+1] = u+1;
						u = p[j][u];
					}
					path[0] = s+1;
					break;
				}
			}
		}

		if (mn == n) 
			puts("no arbitrage sequence exists");
		else {
			cout << path[0];
			for (int i=1; i<mn+2; i++)
				cout << " " << path[i];
			cout << endl;
		}
	}
}
