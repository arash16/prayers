/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 11152
  Name: Colourful Flowers
  Problem: https://onlinejudge.org/external/111/11152.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <math.h>
#include <stdio.h>
#include <iostream>
using namespace std;

#define PI 3.1415926535897932
int main(){
    double a, b, c;
    while (cin>>a>>b>>c) {
        double s = (a+b+c)/2;
        double tr = sqrt(s*(s-a)*(s-b)*(s-c));
        double m = (a+b-c)*(a-b+c)*(-a+b+c);

        double R = sqrt((a*a*b*b*c*c)/(2*m*s));
        double r = sqrt(m/(8*s));

        double C = PI * R*R;
        double c = PI * r*r;

        printf("%.4f %.4f %.4f\n", C-tr, tr-c, c);
    }
}
