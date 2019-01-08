#include<stdio.h>
main()
{
	int x,y;
	
	printf("Please input x:");
	scanf("%d",&x);
	
	y=x;
	while(x<=0)
	{
		y=-x;
		break;
	}
	printf("|x|=%d\n",y);
	
	return 0;
	
	
}
