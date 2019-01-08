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
		switch(x/10)//输入运算条件！ 
		{
			case 9:printf("%d is grade A!\n",x);break;
			case 8:printf("%d is grade B!\n",x);break;
			case 7:printf("%d is grade C!\n",x);break;
			default:printf("%d is grade D!\n",x);break;
		}	
	}
	printf("Goodbye!\n");
	
	return 0;
	
}
