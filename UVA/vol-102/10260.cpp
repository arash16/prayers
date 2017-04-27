#include <stdio.h>
#include <iostream>
using namespace std;

int R[] = { 0, 1, 2, 3, 0, 1, 2, 0, 0, 2, 2, 4, 5, 5, 0, 1, 2, 6, 2, 3, 0, 1, 0, 2, 0, 2 };
int main(){
	char word[30];
	while(cin>>word) {
		int l=-1;
		long long int n = 0;
		for (int i=0; word[i]; i++) {
			int d = R[word[i]-'A'];
			if (d && d!=l)
				n = n*10 + d;
			l = d;
		}
		
		if (!n) cout<<endl;
		else cout<<n<<endl;
	}
}

