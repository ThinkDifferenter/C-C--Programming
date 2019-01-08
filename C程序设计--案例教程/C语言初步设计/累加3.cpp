#include<stdio.h>
main()
{
	int n,i=1,end=1;
	printf("Please input n:");
	scanf("%d",&n);
	
	do
	{
		end*=i;
		i++;
	}
	while(i<=n);
	
	printf("the end is %d\n",end);
	
	return 0;	
}
