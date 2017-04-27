#include <stdio.h>
#include <iostream>
using namespace std;

int main() {
    char str[50];
    int cse = 0;
    while (cin.getline(str, 50) && str[0] != '*')
        printf("Case %d: Hajj-e-%s\n", ++cse, str[0] == 'H' ? "Akbar" : "Asghar");
}
