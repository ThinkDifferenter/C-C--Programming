#include<stdio.h>
main()
{
	
	long i=1,s=0,n;
	printf("Please input n:");
	scanf("%d",&n);
	
	do
	{
		s+=i*(i+1);
		i++;
	}
	while(i<=n);
	
	printf("the result is %d\n",s);
	
	return 0;
}
	
