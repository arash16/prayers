#include <math.h>
#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
    puts("         6         8\n\
        35        49\n\
       204       288\n\
      1189      1681\n\
      6930      9800\n\
     40391     57121\n\
    235416    332928\n\
   1372105   1940449\n\
   7997214  11309768\n\
  46611179  65918161");
/*
    for (long long int y=4; ; y++) {
        long long int x2 = (y&1) ? ((y+1)>>1)*y : (y>>1)*(y+1),
            x = sqrt(x2);

        if (x*x == x2)
            printf("%10lld%10lld\n", x, y);
    }*/
}
