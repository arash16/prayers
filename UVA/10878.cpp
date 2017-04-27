#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
	char line[100];
	bool tape = false;
	while (cin.getline(line, 100)) {
		if (line[0]=='-')
			if (!(tape=!tape)) cout<<endl;
		if (line[0]=='|') {
			int res = 0;
			for (int i=2; i<10; i++)
				if (line[i] == 'o') {
					int p = 6 - (i<6 ? i-2 : i-3);
					res += 1<<p;
				}
			cout << (char)res;
		}
	}
}
