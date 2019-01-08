#include<stdio.h>
main()
{
	int n,i,end=1;
	printf("Please input n:");
	scanf("%d",&n);
	

	for(i=1;i<=n;i++)
	{
		end*=i;
	}
	printf("the end is %d\n",end);
	
	return 0;
}
