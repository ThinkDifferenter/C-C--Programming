#include<stdio.h>
main()
{
	
	long i,s=0,n;
	printf("Please input n:");
	scanf("%d",&n);
	
	i=1;
	while(i<=n)
	{
		s=s+i*(i+1);
		i++;
	}
	printf("the result is %d\n",s);
	
	return 0;
}
	
