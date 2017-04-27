#include <stdio.h>
#include <iostream>
using namespace std;


char d[256];
int main() {
	char lines[]="`1234567890-=\tqwertyuiop[]\\asdfghjkl;'zxcvbnm,./~!@#$%^&*()_+\tQWERTYUIOP{}|ASDFGHJKL:\"ZXCVBNM<>?";
	for(int i=2; lines[i]; i++)
		d[lines[i]] = lines[i-2];
		
	char ch;
	while((ch=getchar()) != EOF) {
		if (ch>='A' && ch<='Z')
			ch += 'a'-'A';
	
		if (d[ch])
			printf("%c", d[ch]);
		else
			cout<<ch;
	}
}
