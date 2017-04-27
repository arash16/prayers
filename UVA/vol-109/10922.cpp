#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
    char line[2000];
    while (cin>>line && (line[0]!='0' || line[1])) {
        int sum = 0, cnt = 1;
        for (int i=0; line[i]; i++)
            sum += line[i] - '0';

        if (sum % 9)
            cout << line << " is not a multiple of 9.\n";

        else {
            int cnt = 1;
            while (sum != 9) {
                int n=sum;
                sum = 0;
                cnt++;
                for (; n; n /= 10)
                    sum += n%10;
            }

            printf("%s is a multiple of 9 and has 9-degree %d.\n", line, cnt);
        }
    }
}
