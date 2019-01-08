#include<stdio.h>
main()
{
	int x,y;
	printf("Please input x:");
	scanf("%d",&x);
	
	
	if(x>0)
	{
		printf("y=%d\n",x+1);
	}
	else if(x=0)
	{
		printf("y=%d\n",x);
	}
	else if(x<0)
	{
		printf("y=%d\n",x-1);
	}
	return 0;
}
