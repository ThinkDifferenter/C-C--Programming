#include<stdio.h>
main()
{
	int n,i,end=1;
	printf("Please input n:");
	scanf("%d",&n);
	
	
	while(i<=n)
	{
		end*=i;
		i++;
	}

	printf("the end is %d\n",end);
	
	return 0;
}
