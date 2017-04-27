#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
	int n, x;
	while (cin>>n && n) {
		bool f = 1;
		for (int i=0; i<n; i++) {
			cin>>x;
			if (x>0) {
				if (f) f=0;
				else cout << " ";
				cout << x;
			}
		}
		if (f) cout << 0;
		cout << endl;
	}
}
