#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
	int a,b,c,d,l;
	while (cin>>a>>b>>c>>d>>l && (a||b||c||d||l)) {
		a%=d;
		b%=d;
		c%=d;
		int cnt=0;
		for (int i=0; i<=l; i++)
			if ( ((((a*i)%d)*i)%d + (b*i)%d + c)%d ==0)
				cnt++;
		
		cout << cnt << endl;
	}
}
