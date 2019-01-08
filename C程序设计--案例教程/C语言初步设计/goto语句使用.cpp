#include<stdio.h>
main() 
{
 int i=1;
 int sum=0;
 
	 loop:sum+=i++;
	 
	 if (i<=100)
	 {goto loop;}//无条件转移语句  
	 
	 printf("sum=%d\n",sum);
	 
	 
 return 0;
  
}


