#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
	int T;
	cin>>T;
	for (int cse = 1; cse<=T; cse++) {
		printf("Case %d: ", cse);

		char c, ch = getchar();
		while (ch<'A' || ch>'Z') ch = getchar();

		while (ch != '\n') {
			int cnt = 0;
			while ((c=getchar())>='0' && c<='9')
				cnt = cnt*10 + c - '0';
			
			for (int i=0; i<cnt; i++)
				putchar(ch);
				
			ch = c;
		}
		putchar('\n');
	}
}
