#include <stdio.h>
#include <math.h>

int main(){
    double a,b,c,s;
    while(scanf("%lf%lf%lf",&a,&b,&c)==3){
        s=(a+b+c)/2.0;
        if(a>0 && b>0 && c>0)
            printf("The radius of the round table is: %.3lf\n",sqrt(((s-a)*(s-b)*(s-c))/s));
        else printf("The radius of the round table is: 0.000\n");
    }
    return 0;
}