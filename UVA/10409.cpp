#include <stdio.h>
#include <iostream>
using namespace std;


void roll(int &x, int &y) {
	int t = 7 - y;
	y = x;
	x = t;
}

int main(){
	int n, t;
	char dir[10];
	while(cin>>n && n) {
		int x=1, y=2, z=3;
		for (int i=0; i<n; i++) {
			cin >> dir;
			switch(dir[0]) {
				case 'n':
					roll(x, y);
					break;
				case 's':
					roll(y, x);
					break;
				case 'w':
					roll(x, z);
					break;
				case 'e':
					roll(z, x);
			}
		}
		cout << x << endl;
	}
}
