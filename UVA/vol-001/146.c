/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 146
  Name: ID Codes
  Problem: https://onlinejudge.org/external/1/146.pdf
  Language: C

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <string.h>
#include <stdio.h>
void swap(char* x,char* y){
     *x+=*y;*y=*x-*y;*x-=*y;
}
int main(){
 char line[60],c;
 int i,j,k,min,len;

 while (gets(line)){
   if(line[0]=='#')break;
   len=strlen(line);
   min=300;

   for(i=len-2;i>=0;i--){
     for(j=i+1;j<len;j++)
       if(line[j]>line[i] && line[j]<min){
         k=j;
         min=line[k];
       }
     if(min!=300){
       swap(&line[i],&line[k]);
       for(j=i+1;j<len;j++)
         for(k=j+1;k<len;k++)
           if(line[j]>line[k])swap(&line[j],&line[k]);
       goto finish;
     }
   }
   printf("No Successor\n");
   continue;
   finish:
   printf("%s\n",line);
 }
 return 0;
}
