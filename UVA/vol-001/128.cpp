#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
	char line[2000];
	while (cin.getline(line, 2000) && (line[0]!='#' || line[1])) {
		unsigned int rem = 0;
		for (int i=0; line[i]; i++)
			rem = ((rem<<8) + line[i]) % 34943;
		rem = (rem<<16) % 34943;

		if (rem > 0) rem = 34943 - rem;
		printf("%02X %02X\n", rem>>8, rem&0xFF);
	}
}
