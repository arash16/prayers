#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
	int T, n, x, y;
	cin>>T;
	while(T--) {
		cin>>n>>x;
		int rs=0, cnt=1;
		for (int i=1; i<n; i++) {
			cin>>y;
			if (rs + x < y) {
				rs += x;
				cnt++;
			}
			x = y;
		}

		cout << cnt << endl;
	}
}
