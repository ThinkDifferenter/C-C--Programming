#include<stdio.h>
main() 
{
 int i=1;
 int sum=0;
 
	 loop:sum+=i++;
	 
	 if (i<=100)
	 {goto loop;}//������ת�����  
	 
	 printf("sum=%d\n",sum);
	 
	 
 return 0;
  
}


