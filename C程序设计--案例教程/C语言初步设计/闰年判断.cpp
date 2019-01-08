#include<stdio.h>
main()
{
	int year,leap=0;
	printf("Please input the year:");
	scanf("%d",&year);
	
	if(year%100!=0)
	{
		if (year%4==0)  leap=1;	
	}
	else
	{
		if (year%400==0)  leap=1;
	}
	if(leap)
	{
		printf("%d is a leap year!\n",year);
	}
	else 
	{
		printf("%d is not a leap year!\n",year);
	}
	
}
