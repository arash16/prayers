/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 438
  Name: The Circumference of the Circle
  Problem: https://onlinejudge.org/external/4/438.pdf
  Language: C

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

const double pi=3.141592653589793;
void swap(double* x,double* y){
     *x+=*y;
     *y=*x-*y;
     *x=*x-*y;
}
int main(){
 double x1,y1,x2,y2,x3,y3,x,y;
 double x21,x23,y21,y23,m,n,r;

 while (scanf("%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3)!=-1){
    while((x2==x3) || (x2==x1)){
      swap(&x1,&x2);swap(&y1,&y2);
      swap(&x1,&x3);swap(&y1,&y3);
    }
    x23=x2-x3;
    x21=x2-x1;
    y23=y2-y3;
    y21=y2-y1;
    m=x1*x1-x2*x2+y1*y1-y2*y2;
    n=x3*x3-x2*x2+y3*y3-y2*y2;
    y=(((n*x21)/x23)-m)/(-2*((y23*x21)/x23)+2*y21);
    x=-(m+2*y*y21)/(2*x21);
    r=sqrt((x-x3)*(x-x3)+(y-y3)*(y-y3));
    printf("%.2lf\n",2*pi*r);
 }
 return 0;
}
