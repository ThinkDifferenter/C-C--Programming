#include<stdio.h>
main()
{
	int n,i=1;
	long t=1;
	
	printf("Please input n: ");
	scanf("%d",&n);
	
	while(n>=i)
	{
		t=t*i;
		i++;	
	
	}
	printf("the result is %d\n",t);
	
	return 0;
	
	
}
