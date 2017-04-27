#include <math.h>
#include <stdio.h>
#include <iostream>
using namespace std;

#define PI 3.1415926535897932

int main(){
    double k1 = 1 + PI/3 - sqrt(3.0);
    double k2 = PI/3 + 2*sqrt(3.0) - 4;
    double k3 = 4 - 2*PI/3 - sqrt(3.0);

    double a;
    while (cin>>a) {
        double a2 = a*a;
        printf("%.3f %.3f %.3f\n", k1*a2, k2*a2, k3*a2);
    }
}

