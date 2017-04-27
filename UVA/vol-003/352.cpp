#include <stdio.h>
#include <cstring>
#include <iostream>
using namespace std;

int n;
bool m[30][30];
void fill(int i, int j) {
	if (i<0 || i>=n || j<0 || j>=n || !m[i][j]) return;
	m[i][j] = 0;
	for (int a=-1; a<2; a++)
		for (int b=-1; b<2; b++)
			if (a || b)
				fill(i+a, j+b);
}


int main(){
	int cse=0;
	while(cin>>n) {
		for (int i=0; i<n; i++) {
			while (getchar()!='\n');
			for (int j=0; j<n; j++)
				m[i][j] = getchar() - '0';
		}
		
		int cnt = 0;
		for (int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				if (m[i][j]) {
					fill(i, j);
					cnt++;
				}

		printf("Image number %d contains %d war eagles.\n", ++cse, cnt);
	}
}
