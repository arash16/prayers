/*
  >>~~ ACM PROBLEM ~~<<

  ID: 10035
  Name: Primary Arithmetic
  Author: Arash Shakery
  Email: arash.shakery@gmail.com
  Language: C
*/

int main()
{
 char n1[12],n2[12];
 int l1,l2,i,count;
 while (scanf("%s%s",&n1,&n2)!=-1)
 {
   if(!strcmp(n1,"0") && !strcmp(n2,"0"))break;
   i=0;
   while(n1[i])i++;
   l1=i;
   i=0;while(n2[i])i++;
   l2=i;
   
   for(i=11;i>=0;i--)
    if(i>11-l1)
     n1[i]=n1[l1+i-12]-48;
    else
     n1[i]=0;

   for(i=11;i>=0;i--)
    if(i>11-l2)
     n2[i]=n2[l2+i-12]-48;
    else
     n2[i]=0;
     
   count=0;
   for(i=11;i;i--)
     if(n1[i]+n2[i]>9)
     {
       count++;
       n1[i-1]++;
     }
     
   if(count)printf("%d",count);
   else printf("No");
   if(count>1)printf(" carry operations.\n");
   else printf(" carry operation.\n");
 }
 return 0;
}
