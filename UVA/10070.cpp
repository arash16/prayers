#include <stdio.h>
#include <iostream>
using namespace std;

bool isleap(int y) {
	return y%400==0 || (y%4==0 && y%100);
}

int main(){
	char ch;
	bool nfirst = false;
	do {
		bool fl = false;
		int m4=0, m100=0, m400=0, m15=0, m55=0;
		while ((ch=getchar())!='\n' && ch!=EOF) {
			fl = true;
			int x = ch - '0';
			m4 = (m4*10+x)%4;
			m15 = (m15*10+x)%15;
			m55 = (m55*10+x)%55;
			m100 = (m100*10+x)%100;
			m400 = (m400*10+x)%400;
		}

		if (fl) {
			if (nfirst) cout << endl;
			else nfirst = true;
		
			bool il = m400==0 || (m4==0 && m100);
			if (il) cout << "This is leap year.\n";
			if (m15==0) cout << "This is huluculu festival year.\n";
			if (il && m55==0) cout << "This is bulukulu festival year.\n";
			if (!il && m15) cout << "This is an ordinary year.\n";
		}
	} while (ch != EOF);
}
