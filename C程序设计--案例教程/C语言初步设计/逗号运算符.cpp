#include<stdio.h>
main()
{
 //逗号表达式 
  int a,b;
   (a=4,b=a+5,b++);
   printf("%d\n",b);
   (b=a=3,b=6*a); 
   printf("%d\n",b);
   
   //按顺序一次计算！ 
   
 
 
 return 0;
 
}


