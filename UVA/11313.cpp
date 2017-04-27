#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
	int T, n, m, cnt;
	cin>>T;
	while (T--) {
		cin >> n >> m;
		for (cnt=0; n>=m; ) {
			cnt += n/m;
			n = (n/m) + (n%m);
		}
		if (n==1) cout << cnt << endl;
		else puts("cannot do this");
	}
}
