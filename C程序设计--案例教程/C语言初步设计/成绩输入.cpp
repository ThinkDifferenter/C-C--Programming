#include<stdio.h>
main()
{
	int x;
	
	printf("Please input x:");//(0<=X<=100)
	scanf("%d",&x);
	
	if(x>100||x<0)
	{
		printf("your input is error!\n ");
	}
	else 
	{
		if(x>=90)
		{
			printf("%d is grade A!\n",x);
		}
		else if(90>x>=80)
		{
			printf("%d is grade B!\n",x);
		}
		else if(80>x>=70)
		{
			printf("%d is grade C!\n,x ");	
		}
		else if(70<x)
		{
			printf("%d is grade D!\n",x);
		}
		
		printf("Goodbye!\n");
		
		return 0;
		
	}
}
