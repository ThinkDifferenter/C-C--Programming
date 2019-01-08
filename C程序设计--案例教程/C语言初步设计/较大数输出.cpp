#include<stdio.h>
main()
{
	int x,y;
	printf("Please input x,y:");
	scanf("%d %d ",&x,&y);
	
	if(x>y)
	{
		printf("%d\n",x);
	}
	else
	{
		printf("%d\n",y);
	}
	return 0;
	
}
