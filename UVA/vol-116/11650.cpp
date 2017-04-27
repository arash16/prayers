#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
	int T, h, m;
	cin>>T;
	while (T--) {
		scanf("%d:%d", &h, &m);

		int t = 720 - (h%12)*60 - m;
		h = t/60; m = t%60;

		printf("%02d:%02d\n", h?h:12, m);
	}
}
