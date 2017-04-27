/*
  >>~~ ACM PROBLEM ~~<<
  
  ID: 10137
  Name: The Trip
  Author: Arash Shakery
  Email: arash.shakery@gmail.com
  Language: C
*/

int main()
{
     double expense[1001],avg1,avg2,sum,sum1,sum2;
     int i,students;

     while (scanf("%d\n",&students)!=-1)
     {
       if(!students)break;
       
       sum=0;
       for(i=1;i<=students;i++)
       {
         scanf("%lf\n",&expense[i]);
         sum+=expense[i];
       }

       avg1=ceil((sum/students)*100)/100;
       avg2=floor((sum/students)*100)/100;

       sum1=0;
       sum2=0;

       for(i=1;i<=students;i++)
         if(expense[i]>avg1)
           sum1+=expense[i]-avg1;

       for(i=1;i<=students;i++)
         if(expense[i]<avg2)
           sum2+=avg2-expense[i];

       sum=sum1>sum2?sum1:sum2;
           
       printf("$%.2lf\n",sum);
     }
  return 0;
}
