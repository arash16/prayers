/*
  >>> ACM PROBLEM <<<
  
  ID: 579
  Name: ClockHands
  Author: Arash Shakery
  Email: arash.shakery@gmail.com
  Language: C++
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
