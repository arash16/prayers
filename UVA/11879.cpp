#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
	char ch;
	for (;;) {
		int n = 0, i=0;
		while ((ch=getchar()) != '\n')
			n = (n*10 + ch - '0') % 17, i++;

		if (i==1 && !n) break;
		puts(n?"0":"1");
	}
}

