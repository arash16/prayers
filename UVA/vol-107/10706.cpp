#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

unsigned int X[210000]={1}, Y[60000]={1};
int main() {
	int cnt;
	for (int i=2, ind=1, digits=1; ;i++) {
		if (i==10 || i==100 || i==1000 || i==10000 || i==100000) digits++;
		int x = i;
		for (int j=digits-1; j>=0; j--) {
			X[ind+j] = x%10;
			x /= 10;
		}
		ind += digits;
		Y[i-1] = Y[i-2] + ind;
		if (Y[i-1]<Y[i-2]) break;
		cnt = i;
	}

	int T, n;
	cin>>T;
	while (T--) {
		cin >> n;
		int yi = lower_bound(Y, Y+cnt, n) - Y;
		if (Y[yi] >= n) yi--;
		cout << X[n-Y[yi]-1] << endl;
	}
}
