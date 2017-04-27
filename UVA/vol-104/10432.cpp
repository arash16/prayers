#include <math.h>
#include <stdio.h>
#include <iostream>
using namespace std;

#define PI 3.1415926535897932
int main(){
    double r, n;
    while (cin>>r>>n) {
        double alpha = PI/n;
        printf("%.3f\n", n*r*r*sin(alpha)*cos(alpha));
    }
}
