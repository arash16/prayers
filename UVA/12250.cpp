#include <stdio.h>
#include <iostream>
#include <string>
#include <map>
using namespace std;

int main(){
	map<string, char*> langs;
	langs[string("HELLO")] = "ENGLISH";
	langs[string("HOLA")] = "SPANISH";
	langs[string("HALLO")] = "GERMAN";
	langs[string("BONJOUR")] = "FRENCH";
	langs[string("CIAO")] = "ITALIAN";
	langs[string("ZDRAVSTVUJTE")] = "RUSSIAN";

	int cse=1;
	char word[20];
	while(cin>>word && (word[1] || word[0]!='#')) {
		char *res = langs[string(word)];
		if (!res || !res[0]) res = "UNKNOWN";
		
		printf("Case %d: %s\n", cse++, res);
	}
}
