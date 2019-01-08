#include<stdio.h>
main()
{
	int x,y;
	printf("Please input x:");
	scanf("%d",&x);
	
	if(x<=0)
	{
		y=-x;
	}
	else
	{
		y=x;
	}
	printf("|x|=%d\n",y);
	
	return 0;
	
}
