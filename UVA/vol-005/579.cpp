/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 579
  Name: Clock Hands
  Problem: https://onlinejudge.org/external/5/579.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <iostream>
#include <cstring>
#include <math.h>
using namespace std;
int main()
{
     int h,m;
     double t;
     char y;
     while (cin>>h>>y>>m && (h || m))
       printf("%.3f\n",(t=fabs(30*h-5.5*m))<180?t:360-t);
  return 0;
}
