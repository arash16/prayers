#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
	int c[9];
	while (scanf("%d%d%d%d%d%d%d%d%d", c, c+1, c+2, c+3, c+4, c+5, c+6, c+7, c+8)==9) {
		int i=0;
		while(!c[i] && i<8) i++;

		if (i==8) cout<<c[i];
		else if (c[i]==-1) cout<<"-";
		else if (c[i]!=1) cout<<c[i];
		if (i<8) cout<<"x";
		if (i<7) cout<<"^"<<(8-i);

		for (i++; i<9; i++)
			if (c[i]) {
				printf(" %c ", c[i]<0?'-':'+');

				int cc = c[i]<0 ? -c[i] : c[i];
				if (cc>1 || i==8) cout<<cc;
				if (i<8) cout<<"x";
				if (i<7) cout<<"^"<<(8-i);
			}
		
		cout<<endl;
	}
}
