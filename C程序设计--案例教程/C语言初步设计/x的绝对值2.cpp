#include<stdio.h>
main()
{
	int x,y;
	
	printf("Please input x:");
	scanf("%d",&x);
	
	y=x;
	if(x<=0)
	{
		y=-x;
	}
	printf("|x|=%d\n",y);
	
	return 0;
	
}
