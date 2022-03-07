/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10432
  Name: Polygon Inside A Circle
  Problem: https://onlinejudge.org/external/104/10432.pdf
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
    double r, n;
    while (cin>>r>>n) {
        double alpha = PI/n;
        printf("%.3f\n", n*r*r*sin(alpha)*cos(alpha));
    }
}
